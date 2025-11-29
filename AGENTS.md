# AGENTS.md - ofxPointClusters

## Build Commands
- **macOS**: Open `example_*/example_*.xcodeproj` in Xcode, select Debug/Release scheme, build
- **Linux**: `cd example_*/ && make` (requires OF_ROOT set or default `../../..`)
- **CI**: Uses openFrameworks standard addon build scripts via Travis/AppVeyor

## Tests
No test framework configured. `tests/` directory is empty placeholder.

## Code Style
- **Indentation**: 2 spaces
- **Braces**: K&R style (opening brace on same line)
- **Classes**: PascalCase (`PointClusters`, `ClusterUpdate`)
- **Methods/variables**: camelCase (`getClusters`, `maxSourcePointsParameter`)
- **Header guards**: `#pragma once`
- **Includes**: Double quotes, order: own header, addon libs, OF headers
- **Modern C++**: Use `auto`, lambdas, range-for, `std::shared_ptr`, brace init
- **ofApp separators**: `//--------------------------------------------------------------` between methods
- **Simple getters**: Inline in header (`size_t size() const { return clusters.size(); };`)

## Error Handling
- Use OF logging (`ofLog`, `ofLogError`, etc.)
- Thread safety via `lock()`/`unlock()` or `ofThreadChannel`
