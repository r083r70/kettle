workspace "kettle"
	architecture "x86_64"
	configurations { "Debug", "Release" }
	startproject "kettle"

include "thirdparty/glfw"
include "thirdparty/glad"
include "thirdparty/imgui"

project "kettle"
	kind "ConsoleApp"

	language "C++"
	cppdialect "C++17"

	targetdir ("bin/%{cfg.buildcfg}")
	objdir ("obj/%{cfg.buildcfg}")

	includedirs {
		"src/",
		"thirdparty/glad/include",
		"thirdparty/glfw/include",
		"thirdparty/imgui"
	}

	links {
		"glfw",
		"glad",
		"imgui"
	}

	files {
		"src/**.h",
		"src/**.cpp",

		-- ImGui files
		"thirdparty/imgui/backends/imgui_impl_glfw.h",
		"thirdparty/imgui/backends/imgui_impl_glfw.cpp",
		"thirdparty/imgui/backends/imgui_impl_opengl3.h",
		"thirdparty/imgui/backends/imgui_impl_opengl3.cpp"
	}

	filter "Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "Release"
		defines { "NDEBUG" }
		optimize "On"

	filter "system:windows"
		systemversion "latest"
		defines { "CP_WINDOWS" }

	filter "system:linux"
		systemversion "latest"
		links { "pthread", "dl" }
		defines { "CP_LINUX" }
