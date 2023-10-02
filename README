A test case to demonstrate the
`  Reason: tried: '/usr/local/lib/libunwind.1.dylib' (no such file), '/usr/lib/libunwind.1.dylib' (no such file, not in dyld cache)`
error from https://github.com/grailbio/bazel-toolchain/issues/224

Building the proto library fails because the built protoc cannot access libunwind:

```
dancrosby@Dans-Mac-Studio grail-test % bazel build //src/main/protobuf:test_proto
INFO: Invocation ID: adc788e9-5344-4ebf-899b-4e39ba626402
INFO: Analyzed target //src/main/protobuf:test_proto (2 packages loaded, 82 targets configured).
INFO: Found 1 target...
ERROR: /Users/dancrosby/CodingProjects/github/grail-test/src/main/protobuf/BUILD.bazel:1:14: Generating Descriptor Set proto_library //src/main/protobuf:test_proto failed: (Aborted): protoc failed: error executing command (from target //src/main/protobuf:test_proto) bazel-out/darwin_arm64-opt-exec-2B5CBBC6/bin/external/protobuf~21.7/protoc --direct_dependencies src/main/protobuf/test.proto ... (remaining 4 arguments skipped)
dyld[68499]: Library not loaded: @rpath/libunwind.1.dylib
  Referenced from: <911CF202-AC7A-32BA-96F0-12E99A322FFE> /private/var/tmp/_bazel_dancrosby/f0d93c3f9e9ba2c50b7eea59373de0a3/execroot/_main/bazel-out/darwin_arm64-opt-exec-2B5CBBC6/bin/external/protobuf~21.7/protoc
  Reason: tried: '/usr/local/lib/libunwind.1.dylib' (no such file), '/usr/lib/libunwind.1.dylib' (no such file, not in dyld cache)
Target //src/main/protobuf:test_proto failed to build
Use --verbose_failures to see the command lines of failed build steps.
INFO: Elapsed time: 5.428s, Critical Path: 0.05s
INFO: 3 processes: 3 internal.
FAILED: Build did NOT complete successfully
```

Note though that the included "Hello World" does build and run correctly:
```
dancrosby@Dans-Mac-Studio grail-test % bazel run //src/main/cpp:main
INFO: Invocation ID: d96df67b-3a52-4e96-b84b-6fade2bc7508
INFO: Analyzed target //src/main/cpp:main (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //src/main/cpp:main up-to-date:
  bazel-bin/src/main/cpp/main
INFO: Elapsed time: 0.088s, Critical Path: 0.00s
INFO: 1 process: 1 internal.
INFO: Build completed successfully, 1 total action
INFO: Running command line: bazel-bin/src/main/cpp/main
Hello, World!
```