workspace "kettleApp"
	architecture "x86_64"
	configurations { "Debug", "Release" }
	startproject "kettleApp"

include "kettleCore"
include "kettleApp"
