class SambucusBerry extends Edible_Base
{
	void SambucusBerry()
	{
	}
	
	bool ConditionAttach ( EntityAI parent )
	{
		//if Barrel_ColorBase
		if ( parent.IsInherited( Barrel_ColorBase ) )
		{
			Barrel_ColorBase barrel = Barrel_ColorBase.Cast( parent );
			
			if ( barrel.IsOpened() && !barrel.FindAttachmentBySlotName( "Nails" ) && !barrel.FindAttachmentBySlotName( "OakBark" ) && !barrel.FindAttachmentBySlotName( "BirchBark" ) && !barrel.FindAttachmentBySlotName( "Lime" ) && !barrel.FindAttachmentBySlotName( "Disinfectant" ) && !barrel.FindAttachmentBySlotName( "Guts" ) )
			{
				return true;
			}
		}
		
		return false;
	}
	
	bool ConditionDetach ( EntityAI parent )
	{
		//if Barrel_ColorBase
		if ( parent.IsInherited( Barrel_ColorBase ) )
		{
			Barrel_ColorBase barrel = Barrel_ColorBase.Cast( parent );
			
			if ( !barrel.IsOpened() )
			{
				return false;
			}
		}
		
		return true;
	}
}

