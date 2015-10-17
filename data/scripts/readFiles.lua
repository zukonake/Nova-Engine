--readFiles.lua
local datasetsPath = "../dataset/generic/"

local objectList =
{
	interfaceList = { },
	aiList = { },
	entityList = { },
	entitySubtypeList = { },
	boardList = { },
	boardGeneratorList = { },
	tileList = { },
	blockList = { },
	blockSubtypeList = { },
}

function listFiles( fileType )
	local result = { }
	for filename in io.popen( "ls " .. datasetPath .. fileType ):lines() do
		table.insert( result, filename )
	end
	return result
end

interfaceList = listFiles( "interface" )
aiList = listFiles( "ai" )
entityList = listFiles( "entity" )
entitySubtypeList = listFiles( "entitySubtype" )
boardList = listFiles( "board" )
boardGeneratorList = listFiles( "boardGenerator" )
tileList = listFiles( "tile" )
blockList = listFiles( "block" )
blockSubtypeList = listFiles( "blockSubtype" )

