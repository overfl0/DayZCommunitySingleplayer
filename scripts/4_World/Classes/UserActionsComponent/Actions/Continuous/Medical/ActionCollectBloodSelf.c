class ActionCollectBloodSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionComponent = new CAContinuousTime(UATimeSpent.COLLECT_BLOOD);
	}
};

class ActionCollectBloodSelf: ActionContinuousBase
{
	private const float PRECISE_SPECIALTY_WEIGHT = -0.03;

	void ActionCollectBloodSelf()
	{
		m_CallbackClass = ActionCollectBloodSelfCB;
		m_MessageStartFail = "Bag is full.";
		m_MessageStart = "I have started collecting blood.";
		m_MessageSuccess = "I have collected my blood.";
		m_MessageFail = "I have moved and collecting blood was canceled.";
		m_MessageCancel = "I stopped collecting blood.";
		//m_Animation = "bandage";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_COLLECTBLOODSELF;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = PRECISE_SPECIALTY_WEIGHT;
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override int GetType()
	{
		return AT_COLLECT_BLOOD_S;
	}
	
	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "collect blood";
	}

	override void OnCompleteServer( PlayerBase player, ActionTarget target, ItemBase item, Param acdata )
	{
		Param1<float> nacdata;
		Class.CastTo(nacdata,  acdata );
		float delta = (nacdata.param1 / UATimeSpent.COLLECT_BLOOD);
		
		ActionCollectBloodTargetLambda lambda = new ActionCollectBloodTargetLambda(item, "BloodBagFull", player, m_SpecialtyWeight, player, delta);
		player.LocalReplaceItemInHandsWithNew(lambda);
	}
	
	override void OnCancelServer( PlayerBase player, ActionTarget target, ItemBase item, Param acdata )
	{
		OnCompleteServer( player, target, item, acdata );
	}
};

