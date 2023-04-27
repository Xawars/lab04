import qbs

CppApplication {
    consoleApplication: true
    install: true
    files: [
        "Network.cpp",
        "Network.h",
        "Router.cpp",
        "Router.h",
        "Test.cpp",
        "Test.h",
        "main.cpp",
    ]
}
