function printfunctions(t)
for i,v in pairs(t) do
if type(v) == "function" then print(i) end
end
end

printfunctions(_G)
for i,v in pairs(_G) do
if type(v) == "table" then
printfunctions(v)
	for ii,vv in pairs(v) do
	if type(vv) == "table" then
printfunctions(vv)
	for iii,vvv in pairs(vv) do
	if type(vvv)=="table" then
printfunctions(vvv)
	for iv,vi in pairs(vvv) do
	if type(vi)=="table" then
	printfunctions(vi)
	for vii,viv in pairs(vi) do
		if type(viv)=="table" then
	printfunctions(viv)
	for viii,vvi in pairs(viv) do
		if type(vvi)=="table" then		
	printfunctions(vvi)
	end
	end
	
	end
end
end
end
end
end
end
end
end
end


