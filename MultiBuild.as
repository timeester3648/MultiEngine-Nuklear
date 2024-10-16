void main(MultiBuild::Workspace& workspace) {	
	auto project = workspace.create_project(".");
	auto properties = project.properties();

	project.name("Nuklear");
	properties.binary_object_kind(MultiBuild::BinaryObjectKind::eStaticLib);
	project.license("./Readme.md");
	properties.tags({ "use_header_only_mle", "utf8" });

	properties.project_includes({
		"fmt",
		"stb",
		"Boost",
		"spdlog",
		"Intrinsics",
		"magic_enum"
	});

	project.include_own_required_includes(true);
	project.add_required_project_include({
		"."
	});

	properties.files({
		"./*.h",
		"./*.cpp"
	});

	{
		MultiBuild::ScopedFilter _(project, "project.compiler:VisualCpp");
		properties.disable_warnings({ "4996", "4244", "4756", "4390" });
	}
}