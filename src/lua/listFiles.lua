--listFiles.lua

function listFiles( directoryPath )
	local result = { }
	for filename in io.popen( "ls " .. directoryPath ):lines() do
		table.insert( result, filename )
	end
	return result
end
