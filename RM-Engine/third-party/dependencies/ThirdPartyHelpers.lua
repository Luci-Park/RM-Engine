function LinkPrebuilt(name, libs)
    includedirs { IncludeDir[name] }
    libdirs { LibDir[name] }
    links(libs)
end

function CopyRuntimeDLL(name, dllFileName)
    if BinDir[name] == nil then
        print("CopyRuntimeDLL: BinDir missing for dep: " .. name)
        return
    end

    postbuildcommands {
        ('{COPYFILE} "%s/%s" "%s/%s"'):format(BinDir[name], dllFileName, "%{cfg.targetdir}", dllFileName)
    }
end

function LinkInstalled(name, libs)
    includedirs { IncludeDir[name] }
    libdirs { LibDir[name] }
    links(libs)
end