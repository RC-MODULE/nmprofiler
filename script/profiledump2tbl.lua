local f = assert(io.open(arg[1], "rb"))

function bytes_to_int(b1, b2, b3, b4)
      if not b4 then error("need four bytes to convert to int",2) end
      local n = b1 + b2*256 + b3*65536 + b4*16777216
      n = (n > 2147483647) and (n - 4294967296) or n
      return n
end

function bytes_to_hex(b1, b2, b3, b4)
      local hex=string.format("%02x%02x%02x%02x",b4,b3,b2,b1)
	  return hex
end

print('summary     ' , 'calls',  'funcaddr', 'name' )
print ('----------------------------------------------')

local bytes = f:read(4)
infosize = bytes_to_int(bytes:byte(1,4))
f:seek ("set", 0)  
	
while true do
--	i = i+1;
--	print ('-------',i)
	local bytes = f:read(4)
	local size = bytes_to_int(bytes:byte(1,4))
	
	bytes = f:read(4)
	local func = bytes_to_hex(bytes:byte(1,4))
--	
	bytes = f:read(4)
	local calls = bytes_to_int(bytes:byte(1,4))
--	
	bytes = f:read(4)
	local summary = bytes_to_hex(bytes:byte(1,4))
--	
	bytes = f:read((infosize-4)*4)
	local t = {}
	for i =0,infosize-4 do
		table.insert (t,string.char(bytes:byte(i*4+1)))
	end 
	local name  = table.concat(t)
	
	print(summary, calls,  func, name )
	if size==0 then break end
end

