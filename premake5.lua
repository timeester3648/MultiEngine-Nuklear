include "../../premake/common_premake_defines.lua"

project "Nuklear"
	kind "StaticLib"
	language "C++"
	cppdialect "C++latest"
	cdialect "C17"
	targetname "%{prj.name}"
	inlining "Auto"

	files {
		"./*.h",
		"./*.cpp"
	}

	includedirs {
		-- Note: no need for seperate static version, since only math is used
		"%{IncludeDir.mle}",
		"%{IncludeDir.fmt}",
		"%{IncludeDir.stb}",
		"%{IncludeDir.boost}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.intrinsics}",
		"%{IncludeDir.magic_enum}",
		"%{IncludeDir.general_includes}"
	}