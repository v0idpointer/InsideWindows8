workspace ("Inside Windows 8")
    platforms { "x86", "amd64" }
    configurations { "Debug", "Release" }

    filter "platforms:x86"
        architecture "x86"

    filter "platforms:amd64"
        architecture "x86_64"

    filter "configurations:Debug"
        runtime "Debug"
        optimize "Off"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        symbols "Off"

    TARGETDIR = "Bin/%{cfg.platform}/%{cfg.buildcfg}/"
    OBJDIR = "Obj/%{cfg.platform}/%{cfg.buildcfg}/"

include "6.1.7779.0.fbl_grfx_dev1.100713-1700/projects.lua"
