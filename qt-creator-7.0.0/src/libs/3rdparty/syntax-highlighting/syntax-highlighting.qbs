import qbs 1.0
import qbs.File
import qbs.FileInfo
import qbs.Environment

Project {
    Product {
        name: "KSyntaxHighlighting"

        Export {
            Depends { name: "qtc" }
            Depends {
                name: "Qt.KSyntaxHighlighting"
                condition: qtc.preferSystemSyntaxHighlighting
                required: false
            }
            Depends {
                name: "KSyntaxHighlighting_bundled"
                required: !qtc.preferSystemSyntaxHighlighting
            }
        }
    }

    QtcLibrary {
        name: "KSyntaxHighlighting_bundled"
        condition: !qtc.preferSystemSyntaxHighlighting || !Qt.KSyntaxHighlighting.present

        cpp.defines: base.concat("KF5SyntaxHighlighting_EXPORTS")
        cpp.includePaths: [
            product.sourceDirectory + "/src/lib/",
            product.sourceDirectory + "/autogenerated/src/lib/",
            product.sourceDirectory + "/autogenerated/"
        ]

        Depends { name: "Qt.gui" }
        Depends { name: "Qt.network" }
        Depends {
            name: "Qt.KSyntaxHighlighting"
            condition: qtc.preferSystemSyntaxHighlighting
            required: false
        }

        Group {
            name: "lib"
            prefix: "src/lib/"
            files: [
                "abstracthighlighter.cpp",
                "abstracthighlighter.h",
                "abstracthighlighter_p.h",
                "context.cpp",
                "context_p.h",
                "contextswitch.cpp",
                "contextswitch_p.h",
                "definition.cpp",
                "definition.h",
                "definition_p.h",
                "definitiondownloader.cpp",
                "definitiondownloader.h",
                "definitionref_p.h",
                "foldingregion.cpp",
                "foldingregion.h",
                "format.cpp",
                "format.h",
                "format_p.h",
                "highlightingdata.cpp",
                "highlightingdata_p.hpp",
                "htmlhighlighter.cpp",
                "htmlhighlighter.h",
                "keywordlist.cpp",
                "keywordlist_p.h",
                "matchresult_p.h",
                "repository.cpp",
                "repository.h",
                "repository_p.h",
                "rule.cpp",
                "rule_p.h",
                "state.cpp",
                "state.h",
                "state_p.h",
                "syntaxhighlighter.cpp",
                "syntaxhighlighter.h",
                "textstyledata_p.h",
                "theme.cpp",
                "theme.h",
                "themedata.cpp",
                "themedata_p.h",
                "wildcardmatcher.cpp",
                "wildcardmatcher_p.h",
                "worddelimiters.cpp",
                "worddelimiters_p.h",
                "xml_p.h",
            ]
        }

        Group {
            name: "KSyntaxHighlighting data"
            qbs.install: true
            qbs.installDir: qtc.ide_data_path + "/generic-highlighter/"
            qbs.installSourceBase: project.ide_source_tree + "/src/libs/3rdparty/syntax-highlighting/data/"
            prefix: project.ide_source_tree + "/src/libs/3rdparty/syntax-highlighting/data/"
            files: [
                "syntax/**/*"
            ]
        }

        Group {
            name: "autogenerated lib"
            prefix: "autogenerated/src/lib/"
            files: [
                "*.h",
                "*.cpp"
            ]
        }

        Group {
            name: "theme data"
            prefix: "data/themes/"
            files: [ "theme-data.qrc" ]
        }

        Export {
            Depends { name: "cpp" }
            cpp.includePaths: [
                exportingProduct.sourceDirectory + "/src/lib/",
                exportingProduct.sourceDirectory + "/autogenerated/src/lib/",
            ]
        }
    }
}
