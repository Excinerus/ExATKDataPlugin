-- include subprojects
includes("lib/commonlibsse")

-- set project constants
set_project("ExATKDataPlugin")
set_version("1.0.0")
set_license("GPL-3.0")
set_languages("c++23")
set_warnings("allextra")

-- add common rules
add_rules("mode.debug", "mode.releasedbg")
add_rules("plugin.vsxmake.autoupdate")

-- define targets
target("ExATKDataPlugin")
    add_rules("commonlibsse.plugin", {
        name = "ExATKDataPlugin",
        author = "excinerus",
        description = "Implements papyrus ReplaceATKData to copy AttackData between BaseActors"
    })

    -- add src files
    add_files("src/**.cpp")
    add_headerfiles("src/**.h")
    add_includedirs("src")
    set_pcxxheader("src/pch.h")
