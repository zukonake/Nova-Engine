--example human definition for Nova-Engine, WIP
local human =
{
	name = "Human",
	body = 
	{
		torso = 
		{
			material = "organic",
			neck =
			{
				material = "organic",
				head =
				{
					rightEye,
					leftEye,
					mouth,
					leftEar,
					rightEar,
					nose
				},
			},
			rightArm =
			{
				rightHand
			},
			leftArm =
			{
				leftHand
			},
			rightLeg = 
			{
				rightFoot
			},
			leftLeg = 
			{
				leftFoot
			},
		},
	}
}
