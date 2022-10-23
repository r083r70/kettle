project "kettleApp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/%{cfg.buildcfg}")
	objdir ("obj/%{cfg.buildcfg}")

	links {
		"kettle"
	}

	includedirs {
		"../kettle/src",
		"../thirdparty/imgui"
	}

	files {
		"src/main.cpp"
	}

	filter "Debug"
		symbols "On"

	filter "Release"
		optimize "On"

	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		links { "pthread", "dl" }
		links { "glad", "GLFW", "imgui" }
		systemversion "latest"
