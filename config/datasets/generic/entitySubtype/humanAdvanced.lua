--example human definition for Nova-Engine, WIP
local human =
{
	canmove = true,
	intelligent = true,
	vision =
	{
		rightEye = true,
		leftEye = true
	},
	liveFunction =
	{
		bloodLevel = 0.6,
		head = 
		{
			self = true,
			brain = true
		},
		torso = true,
	}
	body = 
	{
		joint = "body",
		material = 
		{
			0 = "organicSkin",
			1 = "organicFlesh",
			2 = "organicBone",
			7 = "organicFlesh"
		},
		head = 
		{
			joint = "torso",
			painMultiplier = 7,
			material = 
			{
				0 = "organicSkin",
				1 = "organicFlesh",
				2 = "organicBone",
				3 = "organicFlesh",
				7 = "organicBrain"
			},
			rightEye =
			{
				painMultiplier = 5
				material = 
				{
					7 = "organicEye"
				},
			}
		}
		torso
		rightArm
		leftArm
		rightLeg
		leftLeg
	}
}

