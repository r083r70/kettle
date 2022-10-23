project "kettle"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/%{cfg.buildcfg}")
	objdir ("obj/%{cfg.buildcfg}")

	links {
		"glad",
		"glfw",
		"imgui"
	}

	includedirs {
		"src/",
		"../thirdparty/glad/include",
		"../thirdparty/glfw/include",
		"../thirdparty/imgui"
	}

	files {
		"src/**.h",
		"src/**.cpp"
	}

	filter "Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "Release"
		defines { "NDEBUG" }
		optimize "On"

	filter "system:windows"
		systemversion "latest"
		defines { "KT_WINDOWS" }

	filter "system:linux"
		links { "pthread", "dl" }
		defines { "KT_LINUX" }
		systemversion "latest"
