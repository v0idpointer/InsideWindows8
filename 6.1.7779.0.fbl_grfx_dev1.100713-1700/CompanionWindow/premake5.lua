project ("CompanionWindow")
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"
    targetdir (TARGETDIR)
    objdir (OBJDIR)
    files { "Src/*.cpp" }
    links { "user32", "gdi32" }
