#include "clust.h"
#include <dlfcn.h>
#include <stdlib.h>

#ifdef __cplusplus
"C" {
#endif

cl_api_call_clGetPlatformIDs reallib_clGetPlatformIDs;
cl_api_call_clGetPlatformInfo reallib_clGetPlatformInfo;
cl_api_call_clGetDeviceIDs reallib_clGetDeviceIDs;
cl_api_call_clGetDeviceInfo reallib_clGetDeviceInfo;
cl_api_call_clCreateSubDevices reallib_clCreateSubDevices;
cl_api_call_clRetainDevice reallib_clRetainDevice;
cl_api_call_clReleaseDevice reallib_clReleaseDevice;
cl_api_call_clCreateContext reallib_clCreateContext;
cl_api_call_clCreateContextFromType reallib_clCreateContextFromType;
cl_api_call_clRetainContext reallib_clRetainContext;
cl_api_call_clReleaseContext reallib_clReleaseContext;
cl_api_call_clGetContextInfo reallib_clGetContextInfo;
cl_api_call_clCreateCommandQueueWithProperties reallib_clCreateCommandQueueWithProperties;
cl_api_call_clRetainCommandQueue reallib_clRetainCommandQueue;
cl_api_call_clReleaseCommandQueue reallib_clReleaseCommandQueue;
cl_api_call_clGetCommandQueueInfo reallib_clGetCommandQueueInfo;
cl_api_call_clCreateBuffer reallib_clCreateBuffer;
cl_api_call_clCreateSubBuffer reallib_clCreateSubBuffer;
cl_api_call_clCreateImage reallib_clCreateImage;
cl_api_call_clCreatePipe reallib_clCreatePipe;
cl_api_call_clRetainMemObject reallib_clRetainMemObject;
cl_api_call_clReleaseMemObject reallib_clReleaseMemObject;
cl_api_call_clGetSupportedImageFormats reallib_clGetSupportedImageFormats;
cl_api_call_clGetMemObjectInfo reallib_clGetMemObjectInfo;
cl_api_call_clGetImageInfo reallib_clGetImageInfo;
cl_api_call_clGetPipeInfo reallib_clGetPipeInfo;
cl_api_call_clSetMemObjectDestructorCallback reallib_clSetMemObjectDestructorCallback;
cl_api_call_clSVMAlloc reallib_clSVMAlloc;
cl_api_call_clSVMFree reallib_clSVMFree;
cl_api_call_clCreateSamplerWithProperties reallib_clCreateSamplerWithProperties;
cl_api_call_clRetainSampler reallib_clRetainSampler;
cl_api_call_clReleaseSampler reallib_clReleaseSampler;
cl_api_call_clGetSamplerInfo reallib_clGetSamplerInfo;
cl_api_call_clCreateProgramWithSource reallib_clCreateProgramWithSource;
cl_api_call_clCreateProgramWithBinary reallib_clCreateProgramWithBinary;
cl_api_call_clCreateProgramWithBuiltInKernels reallib_clCreateProgramWithBuiltInKernels;
cl_api_call_clRetainProgram reallib_clRetainProgram;
cl_api_call_clReleaseProgram reallib_clReleaseProgram;
cl_api_call_clBuildProgram reallib_clBuildProgram;
cl_api_call_clCompileProgram reallib_clCompileProgram;
cl_api_call_clLinkProgram reallib_clLinkProgram;
cl_api_call_clUnloadPlatformCompiler reallib_clUnloadPlatformCompiler;
cl_api_call_clGetProgramInfo reallib_clGetProgramInfo;
cl_api_call_clGetProgramBuildInfo reallib_clGetProgramBuildInfo;
cl_api_call_clCreateKernel reallib_clCreateKernel;
cl_api_call_clCreateKernelsInProgram reallib_clCreateKernelsInProgram;
cl_api_call_clRetainKernel reallib_clRetainKernel;
cl_api_call_clReleaseKernel reallib_clReleaseKernel;
cl_api_call_clSetKernelArg reallib_clSetKernelArg;
cl_api_call_clSetKernelArgSVMPointer reallib_clSetKernelArgSVMPointer;
cl_api_call_clSetKernelExecInfo reallib_clSetKernelExecInfo;
cl_api_call_clGetKernelInfo reallib_clGetKernelInfo;
cl_api_call_clGetKernelArgInfo reallib_clGetKernelArgInfo;
cl_api_call_clGetKernelWorkGroupInfo reallib_clGetKernelWorkGroupInfo;
cl_api_call_clWaitForEvents reallib_clWaitForEvents;
cl_api_call_clGetEventInfo reallib_clGetEventInfo;
cl_api_call_clCreateUserEvent reallib_clCreateUserEvent;
cl_api_call_clRetainEvent reallib_clRetainEvent;
cl_api_call_clReleaseEvent reallib_clReleaseEvent;
cl_api_call_clSetUserEventStatus reallib_clSetUserEventStatus;
cl_api_call_clSetEventCallback reallib_clSetEventCallback;
cl_api_call_clGetEventProfilingInfo reallib_clGetEventProfilingInfo;
cl_api_call_clFlush reallib_clFlush;
cl_api_call_clFinish reallib_clFinish;
cl_api_call_clEnqueueReadBuffer reallib_clEnqueueReadBuffer;
cl_api_call_clEnqueueReadBufferRect reallib_clEnqueueReadBufferRect;
cl_api_call_clEnqueueWriteBuffer reallib_clEnqueueWriteBuffer;
cl_api_call_clEnqueueWriteBufferRect reallib_clEnqueueWriteBufferRect;
cl_api_call_clEnqueueFillBuffer reallib_clEnqueueFillBuffer;
cl_api_call_clEnqueueCopyBuffer reallib_clEnqueueCopyBuffer;
cl_api_call_clEnqueueCopyBufferRect reallib_clEnqueueCopyBufferRect;
cl_api_call_clEnqueueReadImage reallib_clEnqueueReadImage;
cl_api_call_clEnqueueWriteImage reallib_clEnqueueWriteImage;
cl_api_call_clEnqueueFillImage reallib_clEnqueueFillImage;
cl_api_call_clEnqueueCopyImage reallib_clEnqueueCopyImage;
cl_api_call_clEnqueueCopyImageToBuffer reallib_clEnqueueCopyImageToBuffer;
cl_api_call_clEnqueueCopyBufferToImage reallib_clEnqueueCopyBufferToImage;
cl_api_call_clEnqueueMapBuffer reallib_clEnqueueMapBuffer;
cl_api_call_clEnqueueMapImage reallib_clEnqueueMapImage;
cl_api_call_clEnqueueUnmapMemObject reallib_clEnqueueUnmapMemObject;
cl_api_call_clEnqueueMigrateMemObjects reallib_clEnqueueMigrateMemObjects;
cl_api_call_clEnqueueNDRangeKernel reallib_clEnqueueNDRangeKernel;
cl_api_call_clEnqueueNativeKernel reallib_clEnqueueNativeKernel;
cl_api_call_clEnqueueMarkerWithWaitList reallib_clEnqueueMarkerWithWaitList;
cl_api_call_clEnqueueBarrierWithWaitList reallib_clEnqueueBarrierWithWaitList;
cl_api_call_clEnqueueSVMFree reallib_clEnqueueSVMFree;
cl_api_call_clEnqueueSVMMemcpy reallib_clEnqueueSVMMemcpy;
cl_api_call_clEnqueueSVMMemFill reallib_clEnqueueSVMMemFill;
cl_api_call_clEnqueueSVMMap reallib_clEnqueueSVMMap;
cl_api_call_clEnqueueSVMUnmap reallib_clEnqueueSVMUnmap;
cl_api_call_clGetExtensionFunctionAddressForPlatform reallib_clGetExtensionFunctionAddressForPlatform;
cl_api_call_clCreateImage2D reallib_clCreateImage2D;
cl_api_call_clCreateImage3D reallib_clCreateImage3D;
cl_api_call_clEnqueueMarker reallib_clEnqueueMarker;
cl_api_call_clEnqueueWaitForEvents reallib_clEnqueueWaitForEvents;
cl_api_call_clEnqueueBarrier reallib_clEnqueueBarrier;
cl_api_call_clUnloadCompiler reallib_clUnloadCompiler;
cl_api_call_clGetExtensionFunctionAddress reallib_clGetExtensionFunctionAddress;
cl_api_call_clCreateCommandQueue reallib_clCreateCommandQueue;
cl_api_call_clCreateSampler reallib_clCreateSampler;
cl_api_call_clEnqueueTask reallib_clEnqueueTask;


void* dlSymFunction(void* libPtr, const char* functionName) {
	void* ptr;
	*(void**)(&ptr) = dlsym(libPtr, functionName);
	if(!ptr) {
		fprintf(stderr, "%s: Unable to load %s\n", LIB_NAME, functionName);
		exit(EXIT_FAILURE);
	}
	return ptr;
}

__attribute__((constructor)) void libCLUST() {
	void* libcl_ptr;
	dlerror();
	libcl_ptr = dlopen(LIBCL_NAME, RTLD_LAZY);

	if(!libcl_ptr) {
		fprintf(stderr, "%s: Unable to load %s\n", LIB_NAME, LIBCL_NAME);
		exit(EXIT_FAILURE);
	}

	dlerror();
	reallib_clGetPlatformIDs = (cl_api_call_clGetPlatformIDs) dlSymFunction(libcl_ptr, "clGetPlatformIDs");
	reallib_clGetPlatformInfo = (cl_api_call_clGetPlatformInfo) dlSymFunction(libcl_ptr, "clGetPlatformInfo");
	reallib_clGetDeviceIDs = (cl_api_call_clGetDeviceIDs) dlSymFunction(libcl_ptr, "clGetDeviceIDs");
	reallib_clGetDeviceInfo = (cl_api_call_clGetDeviceInfo) dlSymFunction(libcl_ptr, "clGetDeviceInfo");
	reallib_clCreateSubDevices = (cl_api_call_clCreateSubDevices) dlSymFunction(libcl_ptr, "clCreateSubDevices");
	reallib_clRetainDevice = (cl_api_call_clRetainDevice) dlSymFunction(libcl_ptr, "clRetainDevice");
	reallib_clReleaseDevice = (cl_api_call_clReleaseDevice) dlSymFunction(libcl_ptr, "clReleaseDevice");
	reallib_clCreateContext = (cl_api_call_clCreateContext) dlSymFunction(libcl_ptr, "clCreateContext");
	reallib_clCreateContextFromType = (cl_api_call_clCreateContextFromType) dlSymFunction(libcl_ptr, "clCreateContextFromType");
	reallib_clRetainContext = (cl_api_call_clRetainContext) dlSymFunction(libcl_ptr, "clRetainContext");
	reallib_clReleaseContext = (cl_api_call_clReleaseContext) dlSymFunction(libcl_ptr, "clReleaseContext");
	reallib_clGetContextInfo = (cl_api_call_clGetContextInfo) dlSymFunction(libcl_ptr, "clGetContextInfo");
	reallib_clCreateCommandQueueWithProperties = (cl_api_call_clCreateCommandQueueWithProperties) dlSymFunction(libcl_ptr, "clCreateCommandQueueWithProperties");
	reallib_clRetainCommandQueue = (cl_api_call_clRetainCommandQueue) dlSymFunction(libcl_ptr, "clRetainCommandQueue");
	reallib_clReleaseCommandQueue = (cl_api_call_clReleaseCommandQueue) dlSymFunction(libcl_ptr, "clReleaseCommandQueue");
	reallib_clGetCommandQueueInfo = (cl_api_call_clGetCommandQueueInfo) dlSymFunction(libcl_ptr, "clGetCommandQueueInfo");
	reallib_clCreateBuffer = (cl_api_call_clCreateBuffer) dlSymFunction(libcl_ptr, "clCreateBuffer");
	reallib_clCreateSubBuffer = (cl_api_call_clCreateSubBuffer) dlSymFunction(libcl_ptr, "clCreateSubBuffer");
	reallib_clCreateImage = (cl_api_call_clCreateImage) dlSymFunction(libcl_ptr, "clCreateImage");
	reallib_clCreatePipe = (cl_api_call_clCreatePipe) dlSymFunction(libcl_ptr, "clCreatePipe");
	reallib_clRetainMemObject = (cl_api_call_clRetainMemObject) dlSymFunction(libcl_ptr, "clRetainMemObject");
	reallib_clReleaseMemObject = (cl_api_call_clReleaseMemObject) dlSymFunction(libcl_ptr, "clReleaseMemObject");
	reallib_clGetSupportedImageFormats = (cl_api_call_clGetSupportedImageFormats) dlSymFunction(libcl_ptr, "clGetSupportedImageFormats");
	reallib_clGetMemObjectInfo = (cl_api_call_clGetMemObjectInfo) dlSymFunction(libcl_ptr, "clGetMemObjectInfo");
	reallib_clGetImageInfo = (cl_api_call_clGetImageInfo) dlSymFunction(libcl_ptr, "clGetImageInfo");
	reallib_clGetPipeInfo = (cl_api_call_clGetPipeInfo) dlSymFunction(libcl_ptr, "clGetPipeInfo");
	reallib_clSetMemObjectDestructorCallback = (cl_api_call_clSetMemObjectDestructorCallback) dlSymFunction(libcl_ptr, "clSetMemObjectDestructorCallback");
	reallib_clSVMAlloc = (cl_api_call_clSVMAlloc) dlSymFunction(libcl_ptr, "clSVMAlloc");
	reallib_clSVMFree = (cl_api_call_clSVMFree) dlSymFunction(libcl_ptr, "clSVMFree");
	reallib_clCreateSamplerWithProperties = (cl_api_call_clCreateSamplerWithProperties) dlSymFunction(libcl_ptr, "clCreateSamplerWithProperties");
	reallib_clRetainSampler = (cl_api_call_clRetainSampler) dlSymFunction(libcl_ptr, "clRetainSampler");
	reallib_clReleaseSampler = (cl_api_call_clReleaseSampler) dlSymFunction(libcl_ptr, "clReleaseSampler");
	reallib_clGetSamplerInfo = (cl_api_call_clGetSamplerInfo) dlSymFunction(libcl_ptr, "clGetSamplerInfo");
	reallib_clCreateProgramWithSource = (cl_api_call_clCreateProgramWithSource) dlSymFunction(libcl_ptr, "clCreateProgramWithSource");
	reallib_clCreateProgramWithBinary = (cl_api_call_clCreateProgramWithBinary) dlSymFunction(libcl_ptr, "clCreateProgramWithBinary");
	reallib_clCreateProgramWithBuiltInKernels = (cl_api_call_clCreateProgramWithBuiltInKernels) dlSymFunction(libcl_ptr, "clCreateProgramWithBuiltInKernels");
	reallib_clRetainProgram = (cl_api_call_clRetainProgram) dlSymFunction(libcl_ptr, "clRetainProgram");
	reallib_clReleaseProgram = (cl_api_call_clReleaseProgram) dlSymFunction(libcl_ptr, "clReleaseProgram");
	reallib_clBuildProgram = (cl_api_call_clBuildProgram) dlSymFunction(libcl_ptr, "clBuildProgram");
	reallib_clCompileProgram = (cl_api_call_clCompileProgram) dlSymFunction(libcl_ptr, "clCompileProgram");
	reallib_clLinkProgram = (cl_api_call_clLinkProgram) dlSymFunction(libcl_ptr, "clLinkProgram");
	reallib_clUnloadPlatformCompiler = (cl_api_call_clUnloadPlatformCompiler) dlSymFunction(libcl_ptr, "clUnloadPlatformCompiler");
	reallib_clGetProgramInfo = (cl_api_call_clGetProgramInfo) dlSymFunction(libcl_ptr, "clGetProgramInfo");
	reallib_clGetProgramBuildInfo = (cl_api_call_clGetProgramBuildInfo) dlSymFunction(libcl_ptr, "clGetProgramBuildInfo");
	reallib_clCreateKernel = (cl_api_call_clCreateKernel) dlSymFunction(libcl_ptr, "clCreateKernel");
	reallib_clCreateKernelsInProgram = (cl_api_call_clCreateKernelsInProgram) dlSymFunction(libcl_ptr, "clCreateKernelsInProgram");
	reallib_clRetainKernel = (cl_api_call_clRetainKernel) dlSymFunction(libcl_ptr, "clRetainKernel");
	reallib_clReleaseKernel = (cl_api_call_clReleaseKernel) dlSymFunction(libcl_ptr, "clReleaseKernel");
	reallib_clSetKernelArg = (cl_api_call_clSetKernelArg) dlSymFunction(libcl_ptr, "clSetKernelArg");
	reallib_clSetKernelArgSVMPointer = (cl_api_call_clSetKernelArgSVMPointer) dlSymFunction(libcl_ptr, "clSetKernelArgSVMPointer");
	reallib_clSetKernelExecInfo = (cl_api_call_clSetKernelExecInfo) dlSymFunction(libcl_ptr, "clSetKernelExecInfo");
	reallib_clGetKernelInfo = (cl_api_call_clGetKernelInfo) dlSymFunction(libcl_ptr, "clGetKernelInfo");
	reallib_clGetKernelArgInfo = (cl_api_call_clGetKernelArgInfo) dlSymFunction(libcl_ptr, "clGetKernelArgInfo");
	reallib_clGetKernelWorkGroupInfo = (cl_api_call_clGetKernelWorkGroupInfo) dlSymFunction(libcl_ptr, "clGetKernelWorkGroupInfo");
	reallib_clWaitForEvents = (cl_api_call_clWaitForEvents) dlSymFunction(libcl_ptr, "clWaitForEvents");
	reallib_clGetEventInfo = (cl_api_call_clGetEventInfo) dlSymFunction(libcl_ptr, "clGetEventInfo");
	reallib_clCreateUserEvent = (cl_api_call_clCreateUserEvent) dlSymFunction(libcl_ptr, "clCreateUserEvent");
	reallib_clRetainEvent = (cl_api_call_clRetainEvent) dlSymFunction(libcl_ptr, "clRetainEvent");
	reallib_clReleaseEvent = (cl_api_call_clReleaseEvent) dlSymFunction(libcl_ptr, "clReleaseEvent");
	reallib_clSetUserEventStatus = (cl_api_call_clSetUserEventStatus) dlSymFunction(libcl_ptr, "clSetUserEventStatus");
	reallib_clSetEventCallback = (cl_api_call_clSetEventCallback) dlSymFunction(libcl_ptr, "clSetEventCallback");
	reallib_clGetEventProfilingInfo = (cl_api_call_clGetEventProfilingInfo) dlSymFunction(libcl_ptr, "clGetEventProfilingInfo");
	reallib_clFlush = (cl_api_call_clFlush) dlSymFunction(libcl_ptr, "clFlush");
	reallib_clFinish = (cl_api_call_clFinish) dlSymFunction(libcl_ptr, "clFinish");
	reallib_clEnqueueReadBuffer = (cl_api_call_clEnqueueReadBuffer) dlSymFunction(libcl_ptr, "clEnqueueReadBuffer");
	reallib_clEnqueueReadBufferRect = (cl_api_call_clEnqueueReadBufferRect) dlSymFunction(libcl_ptr, "clEnqueueReadBufferRect");
	reallib_clEnqueueWriteBuffer = (cl_api_call_clEnqueueWriteBuffer) dlSymFunction(libcl_ptr, "clEnqueueWriteBuffer");
	reallib_clEnqueueWriteBufferRect = (cl_api_call_clEnqueueWriteBufferRect) dlSymFunction(libcl_ptr, "clEnqueueWriteBufferRect");
	reallib_clEnqueueFillBuffer = (cl_api_call_clEnqueueFillBuffer) dlSymFunction(libcl_ptr, "clEnqueueFillBuffer");
	reallib_clEnqueueCopyBuffer = (cl_api_call_clEnqueueCopyBuffer) dlSymFunction(libcl_ptr, "clEnqueueCopyBuffer");
	reallib_clEnqueueCopyBufferRect = (cl_api_call_clEnqueueCopyBufferRect) dlSymFunction(libcl_ptr, "clEnqueueCopyBufferRect");
	reallib_clEnqueueReadImage = (cl_api_call_clEnqueueReadImage) dlSymFunction(libcl_ptr, "clEnqueueReadImage");
	reallib_clEnqueueWriteImage = (cl_api_call_clEnqueueWriteImage) dlSymFunction(libcl_ptr, "clEnqueueWriteImage");
	reallib_clEnqueueFillImage = (cl_api_call_clEnqueueFillImage) dlSymFunction(libcl_ptr, "clEnqueueFillImage");
	reallib_clEnqueueCopyImage = (cl_api_call_clEnqueueCopyImage) dlSymFunction(libcl_ptr, "clEnqueueCopyImage");
	reallib_clEnqueueCopyImageToBuffer = (cl_api_call_clEnqueueCopyImageToBuffer) dlSymFunction(libcl_ptr, "clEnqueueCopyImageToBuffer");
	reallib_clEnqueueCopyBufferToImage = (cl_api_call_clEnqueueCopyBufferToImage) dlSymFunction(libcl_ptr, "clEnqueueCopyBufferToImage");
	reallib_clEnqueueMapBuffer = (cl_api_call_clEnqueueMapBuffer) dlSymFunction(libcl_ptr, "clEnqueueMapBuffer");
	reallib_clEnqueueMapImage = (cl_api_call_clEnqueueMapImage) dlSymFunction(libcl_ptr, "clEnqueueMapImage");
	reallib_clEnqueueUnmapMemObject = (cl_api_call_clEnqueueUnmapMemObject) dlSymFunction(libcl_ptr, "clEnqueueUnmapMemObject");
	reallib_clEnqueueMigrateMemObjects = (cl_api_call_clEnqueueMigrateMemObjects) dlSymFunction(libcl_ptr, "clEnqueueMigrateMemObjects");
	reallib_clEnqueueNDRangeKernel = (cl_api_call_clEnqueueNDRangeKernel) dlSymFunction(libcl_ptr, "clEnqueueNDRangeKernel");
	reallib_clEnqueueNativeKernel = (cl_api_call_clEnqueueNativeKernel) dlSymFunction(libcl_ptr, "clEnqueueNativeKernel");
	reallib_clEnqueueMarkerWithWaitList = (cl_api_call_clEnqueueMarkerWithWaitList) dlSymFunction(libcl_ptr, "clEnqueueMarkerWithWaitList");
	reallib_clEnqueueBarrierWithWaitList = (cl_api_call_clEnqueueBarrierWithWaitList) dlSymFunction(libcl_ptr, "clEnqueueBarrierWithWaitList");
	reallib_clEnqueueSVMFree = (cl_api_call_clEnqueueSVMFree) dlSymFunction(libcl_ptr, "clEnqueueSVMFree");
	reallib_clEnqueueSVMMemcpy = (cl_api_call_clEnqueueSVMMemcpy) dlSymFunction(libcl_ptr, "clEnqueueSVMMemcpy");
	reallib_clEnqueueSVMMemFill = (cl_api_call_clEnqueueSVMMemFill) dlSymFunction(libcl_ptr, "clEnqueueSVMMemFill");
	reallib_clEnqueueSVMMap = (cl_api_call_clEnqueueSVMMap) dlSymFunction(libcl_ptr, "clEnqueueSVMMap");
	reallib_clEnqueueSVMUnmap = (cl_api_call_clEnqueueSVMUnmap) dlSymFunction(libcl_ptr, "clEnqueueSVMUnmap");
	reallib_clGetExtensionFunctionAddressForPlatform = (cl_api_call_clGetExtensionFunctionAddressForPlatform) dlSymFunction(libcl_ptr, "clGetExtensionFunctionAddressForPlatform");
	reallib_clCreateImage2D = (cl_api_call_clCreateImage2D) dlSymFunction(libcl_ptr, "clCreateImage2D");
	reallib_clCreateImage3D = (cl_api_call_clCreateImage3D) dlSymFunction(libcl_ptr, "clCreateImage3D");
	reallib_clEnqueueMarker = (cl_api_call_clEnqueueMarker) dlSymFunction(libcl_ptr, "clEnqueueMarker");
	reallib_clEnqueueWaitForEvents = (cl_api_call_clEnqueueWaitForEvents) dlSymFunction(libcl_ptr, "clEnqueueWaitForEvents");
	reallib_clEnqueueBarrier = (cl_api_call_clEnqueueBarrier) dlSymFunction(libcl_ptr, "clEnqueueBarrier");
	reallib_clUnloadCompiler = (cl_api_call_clUnloadCompiler) dlSymFunction(libcl_ptr, "clUnloadCompiler");
	reallib_clGetExtensionFunctionAddress = (cl_api_call_clGetExtensionFunctionAddress) dlSymFunction(libcl_ptr, "clGetExtensionFunctionAddress");
	reallib_clCreateCommandQueue = (cl_api_call_clCreateCommandQueue) dlSymFunction(libcl_ptr, "clCreateCommandQueue");
	reallib_clCreateSampler = (cl_api_call_clCreateSampler) dlSymFunction(libcl_ptr, "clCreateSampler");
	reallib_clEnqueueTask = (cl_api_call_clEnqueueTask) dlSymFunction(libcl_ptr, "clEnqueueTask");
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetPlatformIDs,

	TP_ARGS(
		cl_uint, num_entries,
		cl_platform_id *, platforms,
		cl_uint *, num_platforms
	),
	TP_FIELDS(
		ctf_integer(cl_uint, num_entries_field, num_entries)
		ctf_integer(cl_platform_id *, platforms_field, platforms)
		ctf_integer(cl_uint *, num_platforms_field, num_platforms)
	)
)
cl_int clGetPlatformIDs(cl_uint num_entries, cl_platform_id * platforms, cl_uint * num_platforms)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetPlatformIDs, num_entries, platforms, num_platforms);
	cl_int ret = reallib_clGetPlatformIDs(num_entries, platforms, num_platforms);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetPlatformInfo,

	TP_ARGS(
		cl_platform_id, platform,
		cl_platform_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_platform_id, platform_field, platform)
		ctf_integer(cl_platform_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetPlatformInfo, platform, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetPlatformInfo(platform, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetDeviceIDs,

	TP_ARGS(
		cl_platform_id, platform,
		cl_device_type, device_type,
		cl_uint, num_entries,
		cl_device_id *, devices,
		cl_uint *, num_devices
	),
	TP_FIELDS(
		ctf_integer(cl_platform_id, platform_field, platform)
		ctf_integer(cl_device_type, device_type_field, device_type)
		ctf_integer(cl_uint, num_entries_field, num_entries)
		ctf_integer(cl_device_id *, devices_field, devices)
		ctf_integer(cl_uint *, num_devices_field, num_devices)
	)
)
cl_int clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type, cl_uint num_entries, cl_device_id * devices, cl_uint * num_devices)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetDeviceIDs, platform, device_type, num_entries, devices, num_devices);
	cl_int ret = reallib_clGetDeviceIDs(platform, device_type, num_entries, devices, num_devices);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetDeviceInfo,

	TP_ARGS(
		cl_device_id, device,
		cl_device_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_device_id, device_field, device)
		ctf_integer(cl_device_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetDeviceInfo, device, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetDeviceInfo(device, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateSubDevices,

	TP_ARGS(
		cl_device_id, in_device,
		const cl_device_partition_property *, properties,
		cl_uint, num_devices,
		cl_device_id *, out_devices,
		cl_uint *, num_devices_ret
	),
	TP_FIELDS(
		ctf_integer(cl_device_id, in_device_field, in_device)
		ctf_integer(const cl_device_partition_property *, properties_field, properties)
		ctf_integer(cl_uint, num_devices_field, num_devices)
		ctf_integer(cl_device_id *, out_devices_field, out_devices)
		ctf_integer(cl_uint *, num_devices_ret_field, num_devices_ret)
	)
)
cl_int clCreateSubDevices(cl_device_id in_device, const cl_device_partition_property * properties, cl_uint num_devices, cl_device_id * out_devices, cl_uint * num_devices_ret)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clCreateSubDevices, in_device, properties, num_devices, out_devices, num_devices_ret);
	cl_int ret = reallib_clCreateSubDevices(in_device, properties, num_devices, out_devices, num_devices_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainDevice,

	TP_ARGS(
		cl_device_id, device
	),
	TP_FIELDS(
		ctf_integer(cl_device_id, device_field, device)
	)
)
cl_int clRetainDevice(cl_device_id device)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clRetainDevice, device);
	cl_int ret = reallib_clRetainDevice(device);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseDevice,

	TP_ARGS(
		cl_device_id, device
	),
	TP_FIELDS(
		ctf_integer(cl_device_id, device_field, device)
	)
)
cl_int clReleaseDevice(cl_device_id device)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clReleaseDevice, device);
	cl_int ret = reallib_clReleaseDevice(device);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateContext,

	TP_ARGS(
		const cl_context_properties *, properties,
		cl_uint, num_devices,
		const cl_device_id *, devices,
		void (CL_CALLBACK * )(const char *, const void *, size_t, void *), pfn_notify,
		void *, param_4,
		cl_int *, user_data
	),
	TP_FIELDS(
		ctf_integer(const cl_context_properties *, properties_field, properties)
		ctf_integer(cl_uint, num_devices_field, num_devices)
		ctf_integer(const cl_device_id *, devices_field, devices)
		ctf_integer(void (CL_CALLBACK * )(const char *, const void *, size_t, void *), pfn_notify_field, pfn_notify)
		ctf_integer(void *, param_4_field, param_4)
		ctf_integer(cl_int *, user_data_field, user_data)
	)
)
cl_context clCreateContext(const cl_context_properties * properties, cl_uint num_devices, const cl_device_id * devices, void (CL_CALLBACK * )(const char *, const void *, size_t, void *) pfn_notify, void * param_4, cl_int * user_data)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateContext, properties, num_devices, devices, pfn_notify, param_4, user_data);
	cl_context ret = reallib_clCreateContext(properties, num_devices, devices, pfn_notify, param_4, user_data);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateContextFromType,

	TP_ARGS(
		const cl_context_properties *, properties,
		cl_device_type, device_type,
		void (CL_CALLBACK * )(const char *, const void *, size_t, void *), pfn_notify,
		void *, param_3,
		cl_int *, user_data
	),
	TP_FIELDS(
		ctf_integer(const cl_context_properties *, properties_field, properties)
		ctf_integer(cl_device_type, device_type_field, device_type)
		ctf_integer(void (CL_CALLBACK * )(const char *, const void *, size_t, void *), pfn_notify_field, pfn_notify)
		ctf_integer(void *, param_3_field, param_3)
		ctf_integer(cl_int *, user_data_field, user_data)
	)
)
cl_context clCreateContextFromType(const cl_context_properties * properties, cl_device_type device_type, void (CL_CALLBACK * )(const char *, const void *, size_t, void *) pfn_notify, void * param_3, cl_int * user_data)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateContextFromType, properties, device_type, pfn_notify, param_3, user_data);
	cl_context ret = reallib_clCreateContextFromType(properties, device_type, pfn_notify, param_3, user_data);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainContext,

	TP_ARGS(
		cl_context, context
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
	)
)
cl_int clRetainContext(cl_context context)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainContext, context);
	cl_int ret = reallib_clRetainContext(context);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseContext,

	TP_ARGS(
		cl_context, context
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
	)
)
cl_int clReleaseContext(cl_context context)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseContext, context);
	cl_int ret = reallib_clReleaseContext(context);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetContextInfo,

	TP_ARGS(
		cl_context, context,
		cl_context_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_context_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetContextInfo(cl_context context, cl_context_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetContextInfo, context, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetContextInfo(context, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateCommandQueueWithProperties,

	TP_ARGS(
		cl_context, context,
		cl_device_id, device,
		const cl_queue_properties *, properties,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_device_id, device_field, device)
		ctf_integer(const cl_queue_properties *, properties_field, properties)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_command_queue clCreateCommandQueueWithProperties(cl_context context, cl_device_id device, const cl_queue_properties * properties, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_2_0 {
	tracepoint(clust_provider, clust_clCreateCommandQueueWithProperties, context, device, properties, errcode_ret);
	cl_command_queue ret = reallib_clCreateCommandQueueWithProperties(context, device, properties, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainCommandQueue,

	TP_ARGS(
		cl_command_queue, command_queue
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
	)
)
cl_int clRetainCommandQueue(cl_command_queue command_queue)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainCommandQueue, command_queue);
	cl_int ret = reallib_clRetainCommandQueue(command_queue);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseCommandQueue,

	TP_ARGS(
		cl_command_queue, command_queue
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
	)
)
cl_int clReleaseCommandQueue(cl_command_queue command_queue)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseCommandQueue, command_queue);
	cl_int ret = reallib_clReleaseCommandQueue(command_queue);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetCommandQueueInfo,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_command_queue_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_command_queue_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetCommandQueueInfo(cl_command_queue command_queue, cl_command_queue_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetCommandQueueInfo, command_queue, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetCommandQueueInfo(command_queue, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateBuffer,

	TP_ARGS(
		cl_context, context,
		cl_mem_flags, flags,
		size_t, size,
		void *, host_ptr,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_mem_flags, flags_field, flags)
		ctf_integer(size_t, size_field, size)
		ctf_integer(void *, host_ptr_field, host_ptr)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_mem clCreateBuffer(cl_context context, cl_mem_flags flags, size_t size, void * host_ptr, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateBuffer, context, flags, size, host_ptr, errcode_ret);
	cl_mem ret = reallib_clCreateBuffer(context, flags, size, host_ptr, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateSubBuffer,

	TP_ARGS(
		cl_mem, buffer,
		cl_mem_flags, flags,
		cl_buffer_create_type, buffer_create_type,
		const void *, buffer_create_info,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_mem_flags, flags_field, flags)
		ctf_integer(cl_buffer_create_type, buffer_create_type_field, buffer_create_type)
		ctf_integer(const void *, buffer_create_info_field, buffer_create_info)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_mem clCreateSubBuffer(cl_mem buffer, cl_mem_flags flags, cl_buffer_create_type buffer_create_type, const void * buffer_create_info, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clCreateSubBuffer, buffer, flags, buffer_create_type, buffer_create_info, errcode_ret);
	cl_mem ret = reallib_clCreateSubBuffer(buffer, flags, buffer_create_type, buffer_create_info, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateImage,

	TP_ARGS(
		cl_context, context,
		cl_mem_flags, flags,
		const cl_image_format *, image_format,
		const cl_image_desc *, image_desc,
		void *, host_ptr,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_mem_flags, flags_field, flags)
		ctf_integer(const cl_image_format *, image_format_field, image_format)
		ctf_integer(const cl_image_desc *, image_desc_field, image_desc)
		ctf_integer(void *, host_ptr_field, host_ptr)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_mem clCreateImage(cl_context context, cl_mem_flags flags, const cl_image_format * image_format, const cl_image_desc * image_desc, void * host_ptr, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clCreateImage, context, flags, image_format, image_desc, host_ptr, errcode_ret);
	cl_mem ret = reallib_clCreateImage(context, flags, image_format, image_desc, host_ptr, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreatePipe,

	TP_ARGS(
		cl_context, context,
		cl_mem_flags, flags,
		cl_uint, pipe_packet_size,
		cl_uint, pipe_max_packets,
		const cl_pipe_properties *, properties,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_mem_flags, flags_field, flags)
		ctf_integer(cl_uint, pipe_packet_size_field, pipe_packet_size)
		ctf_integer(cl_uint, pipe_max_packets_field, pipe_max_packets)
		ctf_integer(const cl_pipe_properties *, properties_field, properties)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_mem clCreatePipe(cl_context context, cl_mem_flags flags, cl_uint pipe_packet_size, cl_uint pipe_max_packets, const cl_pipe_properties * properties, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_2_0 {
	tracepoint(clust_provider, clust_clCreatePipe, context, flags, pipe_packet_size, pipe_max_packets, properties, errcode_ret);
	cl_mem ret = reallib_clCreatePipe(context, flags, pipe_packet_size, pipe_max_packets, properties, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainMemObject,

	TP_ARGS(
		cl_mem, memobj
	),
	TP_FIELDS(
		ctf_integer(cl_mem, memobj_field, memobj)
	)
)
cl_int clRetainMemObject(cl_mem memobj)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainMemObject, memobj);
	cl_int ret = reallib_clRetainMemObject(memobj);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseMemObject,

	TP_ARGS(
		cl_mem, memobj
	),
	TP_FIELDS(
		ctf_integer(cl_mem, memobj_field, memobj)
	)
)
cl_int clReleaseMemObject(cl_mem memobj)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseMemObject, memobj);
	cl_int ret = reallib_clReleaseMemObject(memobj);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetSupportedImageFormats,

	TP_ARGS(
		cl_context, context,
		cl_mem_flags, flags,
		cl_mem_object_type, image_type,
		cl_uint, num_entries,
		cl_image_format *, image_formats,
		cl_uint *, num_image_formats
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_mem_flags, flags_field, flags)
		ctf_integer(cl_mem_object_type, image_type_field, image_type)
		ctf_integer(cl_uint, num_entries_field, num_entries)
		ctf_integer(cl_image_format *, image_formats_field, image_formats)
		ctf_integer(cl_uint *, num_image_formats_field, num_image_formats)
	)
)
cl_int clGetSupportedImageFormats(cl_context context, cl_mem_flags flags, cl_mem_object_type image_type, cl_uint num_entries, cl_image_format * image_formats, cl_uint * num_image_formats)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetSupportedImageFormats, context, flags, image_type, num_entries, image_formats, num_image_formats);
	cl_int ret = reallib_clGetSupportedImageFormats(context, flags, image_type, num_entries, image_formats, num_image_formats);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetMemObjectInfo,

	TP_ARGS(
		cl_mem, memobj,
		cl_mem_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_mem, memobj_field, memobj)
		ctf_integer(cl_mem_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetMemObjectInfo(cl_mem memobj, cl_mem_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetMemObjectInfo, memobj, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetMemObjectInfo(memobj, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetImageInfo,

	TP_ARGS(
		cl_mem, image,
		cl_image_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_mem, image_field, image)
		ctf_integer(cl_image_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetImageInfo(cl_mem image, cl_image_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetImageInfo, image, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetImageInfo(image, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetPipeInfo,

	TP_ARGS(
		cl_mem, pipe,
		cl_pipe_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_mem, pipe_field, pipe)
		ctf_integer(cl_pipe_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetPipeInfo(cl_mem pipe, cl_pipe_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_2_0 {
	tracepoint(clust_provider, clust_clGetPipeInfo, pipe, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetPipeInfo(pipe, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSetMemObjectDestructorCallback,

	TP_ARGS(
		cl_mem, memobj,
		void (CL_CALLBACK * )( cl_mem , void* ), pfn_notify,
		void *, user_data
	),
	TP_FIELDS(
		ctf_integer(cl_mem, memobj_field, memobj)
		ctf_integer(void (CL_CALLBACK * )( cl_mem , void* ), pfn_notify_field, pfn_notify)
		ctf_integer(void *, user_data_field, user_data)
	)
)
cl_int clSetMemObjectDestructorCallback(cl_mem memobj, void (CL_CALLBACK * )( cl_mem , void* ) pfn_notify, void * user_data)              CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clSetMemObjectDestructorCallback, memobj, pfn_notify, user_data);
	cl_int ret = reallib_clSetMemObjectDestructorCallback(memobj, pfn_notify, user_data);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSVMAlloc,

	TP_ARGS(
		cl_context, context,
		cl_svm_mem_flags, flags,
		size_t, size,
		cl_uint, alignment
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_svm_mem_flags, flags_field, flags)
		ctf_integer(size_t, size_field, size)
		ctf_integer(cl_uint, alignment_field, alignment)
	)
)
void * clSVMAlloc(cl_context context, cl_svm_mem_flags flags, size_t size, cl_uint alignment)  CL_API_SUFFIX__VERSION_2_0 {
	tracepoint(clust_provider, clust_clSVMAlloc, context, flags, size, alignment);
	void * ret = reallib_clSVMAlloc(context, flags, size, alignment);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSVMFree,

	TP_ARGS(
		cl_context, context,
		void *, svm_pointer
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(void *, svm_pointer_field, svm_pointer)
	)
)
void clSVMFree(cl_context context, void * svm_pointer)  CL_API_SUFFIX__VERSION_2_0 {
	tracepoint(clust_provider, clust_clSVMFree, context, svm_pointer);
	void ret = reallib_clSVMFree(context, svm_pointer);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateSamplerWithProperties,

	TP_ARGS(
		cl_context, context,
		const cl_sampler_properties *, normalized_coords,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(const cl_sampler_properties *, normalized_coords_field, normalized_coords)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_sampler clCreateSamplerWithProperties(cl_context context, const cl_sampler_properties * normalized_coords, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_2_0 {
	tracepoint(clust_provider, clust_clCreateSamplerWithProperties, context, normalized_coords, errcode_ret);
	cl_sampler ret = reallib_clCreateSamplerWithProperties(context, normalized_coords, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainSampler,

	TP_ARGS(
		cl_sampler, sampler
	),
	TP_FIELDS(
		ctf_integer(cl_sampler, sampler_field, sampler)
	)
)
cl_int clRetainSampler(cl_sampler sampler)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainSampler, sampler);
	cl_int ret = reallib_clRetainSampler(sampler);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseSampler,

	TP_ARGS(
		cl_sampler, sampler
	),
	TP_FIELDS(
		ctf_integer(cl_sampler, sampler_field, sampler)
	)
)
cl_int clReleaseSampler(cl_sampler sampler)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseSampler, sampler);
	cl_int ret = reallib_clReleaseSampler(sampler);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetSamplerInfo,

	TP_ARGS(
		cl_sampler, sampler,
		cl_sampler_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_sampler, sampler_field, sampler)
		ctf_integer(cl_sampler_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetSamplerInfo(cl_sampler sampler, cl_sampler_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetSamplerInfo, sampler, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetSamplerInfo(sampler, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateProgramWithSource,

	TP_ARGS(
		cl_context, context,
		cl_uint, count,
		const char **, strings,
		const size_t *, lengths,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_uint, count_field, count)
		ctf_integer(const char **, strings_field, strings)
		ctf_integer(const size_t *, lengths_field, lengths)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_program clCreateProgramWithSource(cl_context context, cl_uint count, const char ** strings, const size_t * lengths, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateProgramWithSource, context, count, strings, lengths, errcode_ret);
	cl_program ret = reallib_clCreateProgramWithSource(context, count, strings, lengths, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateProgramWithBinary,

	TP_ARGS(
		cl_context, context,
		cl_uint, num_devices,
		const cl_device_id *, device_list,
		const size_t *, lengths,
		const unsigned char **, binaries,
		cl_int *, binary_status,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_uint, num_devices_field, num_devices)
		ctf_integer(const cl_device_id *, device_list_field, device_list)
		ctf_integer(const size_t *, lengths_field, lengths)
		ctf_integer(const unsigned char **, binaries_field, binaries)
		ctf_integer(cl_int *, binary_status_field, binary_status)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_program clCreateProgramWithBinary(cl_context context, cl_uint num_devices, const cl_device_id * device_list, const size_t * lengths, const unsigned char ** binaries, cl_int * binary_status, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateProgramWithBinary, context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
	cl_program ret = reallib_clCreateProgramWithBinary(context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateProgramWithBuiltInKernels,

	TP_ARGS(
		cl_context, context,
		cl_uint, num_devices,
		const cl_device_id *, device_list,
		const char *, kernel_names,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_uint, num_devices_field, num_devices)
		ctf_integer(const cl_device_id *, device_list_field, device_list)
		ctf_integer(const char *, kernel_names_field, kernel_names)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_program clCreateProgramWithBuiltInKernels(cl_context context, cl_uint num_devices, const cl_device_id * device_list, const char * kernel_names, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clCreateProgramWithBuiltInKernels, context, num_devices, device_list, kernel_names, errcode_ret);
	cl_program ret = reallib_clCreateProgramWithBuiltInKernels(context, num_devices, device_list, kernel_names, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainProgram,

	TP_ARGS(
		cl_program, program
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
	)
)
cl_int clRetainProgram(cl_program program)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainProgram, program);
	cl_int ret = reallib_clRetainProgram(program);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseProgram,

	TP_ARGS(
		cl_program, program
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
	)
)
cl_int clReleaseProgram(cl_program program)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseProgram, program);
	cl_int ret = reallib_clReleaseProgram(program);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clBuildProgram,

	TP_ARGS(
		cl_program, program,
		cl_uint, num_devices,
		const cl_device_id *, device_list,
		const char *, options,
		void (CL_CALLBACK * )(cl_program , void * ), pfn_notify,
		void *, user_data
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(cl_uint, num_devices_field, num_devices)
		ctf_integer(const cl_device_id *, device_list_field, device_list)
		ctf_integer(const char *, options_field, options)
		ctf_integer(void (CL_CALLBACK * )(cl_program , void * ), pfn_notify_field, pfn_notify)
		ctf_integer(void *, user_data_field, user_data)
	)
)
cl_int clBuildProgram(cl_program program, cl_uint num_devices, const cl_device_id * device_list, const char * options, void (CL_CALLBACK * )(cl_program , void * ) pfn_notify, void * user_data)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clBuildProgram, program, num_devices, device_list, options, pfn_notify, user_data);
	cl_int ret = reallib_clBuildProgram(program, num_devices, device_list, options, pfn_notify, user_data);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCompileProgram,

	TP_ARGS(
		cl_program, program,
		cl_uint, num_devices,
		const cl_device_id *, device_list,
		const char *, options,
		cl_uint, num_input_headers,
		const cl_program *, input_headers,
		const char **, header_include_names,
		void (CL_CALLBACK * )(cl_program , void * ), pfn_notify,
		void *, user_data
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(cl_uint, num_devices_field, num_devices)
		ctf_integer(const cl_device_id *, device_list_field, device_list)
		ctf_integer(const char *, options_field, options)
		ctf_integer(cl_uint, num_input_headers_field, num_input_headers)
		ctf_integer(const cl_program *, input_headers_field, input_headers)
		ctf_integer(const char **, header_include_names_field, header_include_names)
		ctf_integer(void (CL_CALLBACK * )(cl_program , void * ), pfn_notify_field, pfn_notify)
		ctf_integer(void *, user_data_field, user_data)
	)
)
cl_int clCompileProgram(cl_program program, cl_uint num_devices, const cl_device_id * device_list, const char * options, cl_uint num_input_headers, const cl_program * input_headers, const char ** header_include_names, void (CL_CALLBACK * )(cl_program , void * ) pfn_notify, void * user_data)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clCompileProgram, program, num_devices, device_list, options, num_input_headers, input_headers, header_include_names, pfn_notify, user_data);
	cl_int ret = reallib_clCompileProgram(program, num_devices, device_list, options, num_input_headers, input_headers, header_include_names, pfn_notify, user_data);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clLinkProgram,

	TP_ARGS(
		cl_context, context,
		cl_uint, num_devices,
		const cl_device_id *, device_list,
		const char *, options,
		cl_uint, num_input_programs,
		const cl_program *, input_programs,
		void (CL_CALLBACK * )(cl_program , void * ), pfn_notify,
		void *, user_data,
		cl_int *, user_data
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_uint, num_devices_field, num_devices)
		ctf_integer(const cl_device_id *, device_list_field, device_list)
		ctf_integer(const char *, options_field, options)
		ctf_integer(cl_uint, num_input_programs_field, num_input_programs)
		ctf_integer(const cl_program *, input_programs_field, input_programs)
		ctf_integer(void (CL_CALLBACK * )(cl_program , void * ), pfn_notify_field, pfn_notify)
		ctf_integer(void *, user_data_field, user_data)
		ctf_integer(cl_int *, user_data_field, user_data)
	)
)
cl_program clLinkProgram(cl_context context, cl_uint num_devices, const cl_device_id * device_list, const char * options, cl_uint num_input_programs, const cl_program * input_programs, void (CL_CALLBACK * )(cl_program , void * ) pfn_notify, void * user_data, cl_int * user_data)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clLinkProgram, context, num_devices, device_list, options, num_input_programs, input_programs, pfn_notify, user_data, user_data);
	cl_program ret = reallib_clLinkProgram(context, num_devices, device_list, options, num_input_programs, input_programs, pfn_notify, user_data, user_data);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clUnloadPlatformCompiler,

	TP_ARGS(
		cl_platform_id, platform
	),
	TP_FIELDS(
		ctf_integer(cl_platform_id, platform_field, platform)
	)
)
cl_int clUnloadPlatformCompiler(cl_platform_id platform)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clUnloadPlatformCompiler, platform);
	cl_int ret = reallib_clUnloadPlatformCompiler(platform);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetProgramInfo,

	TP_ARGS(
		cl_program, program,
		cl_program_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(cl_program_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetProgramInfo(cl_program program, cl_program_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetProgramInfo, program, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetProgramInfo(program, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetProgramBuildInfo,

	TP_ARGS(
		cl_program, program,
		cl_device_id, device,
		cl_program_build_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(cl_device_id, device_field, device)
		ctf_integer(cl_program_build_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetProgramBuildInfo(cl_program program, cl_device_id device, cl_program_build_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetProgramBuildInfo, program, device, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetProgramBuildInfo(program, device, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateKernel,

	TP_ARGS(
		cl_program, program,
		const char *, kernel_name,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(const char *, kernel_name_field, kernel_name)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_kernel clCreateKernel(cl_program program, const char * kernel_name, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateKernel, program, kernel_name, errcode_ret);
	cl_kernel ret = reallib_clCreateKernel(program, kernel_name, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateKernelsInProgram,

	TP_ARGS(
		cl_program, program,
		cl_uint, num_kernels,
		cl_kernel *, kernels,
		cl_uint *, num_kernels_ret
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(cl_uint, num_kernels_field, num_kernels)
		ctf_integer(cl_kernel *, kernels_field, kernels)
		ctf_integer(cl_uint *, num_kernels_ret_field, num_kernels_ret)
	)
)
cl_int clCreateKernelsInProgram(cl_program program, cl_uint num_kernels, cl_kernel * kernels, cl_uint * num_kernels_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateKernelsInProgram, program, num_kernels, kernels, num_kernels_ret);
	cl_int ret = reallib_clCreateKernelsInProgram(program, num_kernels, kernels, num_kernels_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainKernel,

	TP_ARGS(
		cl_kernel, kernel
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
	)
)
cl_int clRetainKernel(cl_kernel kernel)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainKernel, kernel);
	cl_int ret = reallib_clRetainKernel(kernel);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseKernel,

	TP_ARGS(
		cl_kernel, kernel
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
	)
)
cl_int clReleaseKernel(cl_kernel kernel)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseKernel, kernel);
	cl_int ret = reallib_clReleaseKernel(kernel);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSetKernelArg,

	TP_ARGS(
		cl_kernel, kernel,
		cl_uint, arg_index,
		size_t, arg_size,
		const void *, arg_value
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_uint, arg_index_field, arg_index)
		ctf_integer(size_t, arg_size_field, arg_size)
		ctf_integer(const void *, arg_value_field, arg_value)
	)
)
cl_int clSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void * arg_value)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clSetKernelArg, kernel, arg_index, arg_size, arg_value);
	cl_int ret = reallib_clSetKernelArg(kernel, arg_index, arg_size, arg_value);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSetKernelArgSVMPointer,

	TP_ARGS(
		cl_kernel, kernel,
		cl_uint, arg_index,
		const void *, arg_value
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_uint, arg_index_field, arg_index)
		ctf_integer(const void *, arg_value_field, arg_value)
	)
)
cl_int clSetKernelArgSVMPointer(cl_kernel kernel, cl_uint arg_index, const void * arg_value)  CL_API_SUFFIX__VERSION_2_0 {
	tracepoint(clust_provider, clust_clSetKernelArgSVMPointer, kernel, arg_index, arg_value);
	cl_int ret = reallib_clSetKernelArgSVMPointer(kernel, arg_index, arg_value);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSetKernelExecInfo,

	TP_ARGS(
		cl_kernel, kernel,
		cl_kernel_exec_info, param_name,
		size_t, param_value_size,
		const void *, param_value
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_kernel_exec_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(const void *, param_value_field, param_value)
	)
)
cl_int clSetKernelExecInfo(cl_kernel kernel, cl_kernel_exec_info param_name, size_t param_value_size, const void * param_value)  CL_API_SUFFIX__VERSION_2_0 {
	tracepoint(clust_provider, clust_clSetKernelExecInfo, kernel, param_name, param_value_size, param_value);
	cl_int ret = reallib_clSetKernelExecInfo(kernel, param_name, param_value_size, param_value);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetKernelInfo,

	TP_ARGS(
		cl_kernel, kernel,
		cl_kernel_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_kernel_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetKernelInfo, kernel, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetKernelInfo(kernel, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetKernelArgInfo,

	TP_ARGS(
		cl_kernel, kernel,
		cl_uint, arg_indx,
		cl_kernel_arg_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_uint, arg_indx_field, arg_indx)
		ctf_integer(cl_kernel_arg_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetKernelArgInfo(cl_kernel kernel, cl_uint arg_indx, cl_kernel_arg_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clGetKernelArgInfo, kernel, arg_indx, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetKernelArgInfo(kernel, arg_indx, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetKernelWorkGroupInfo,

	TP_ARGS(
		cl_kernel, kernel,
		cl_device_id, device,
		cl_kernel_work_group_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_device_id, device_field, device)
		ctf_integer(cl_kernel_work_group_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetKernelWorkGroupInfo, kernel, device, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetKernelWorkGroupInfo(kernel, device, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clWaitForEvents,

	TP_ARGS(
		cl_uint, num_events,
		const cl_event *, event_list
	),
	TP_FIELDS(
		ctf_integer(cl_uint, num_events_field, num_events)
		ctf_integer(const cl_event *, event_list_field, event_list)
	)
)
cl_int clWaitForEvents(cl_uint num_events, const cl_event * event_list)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clWaitForEvents, num_events, event_list);
	cl_int ret = reallib_clWaitForEvents(num_events, event_list);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetEventInfo,

	TP_ARGS(
		cl_event, event,
		cl_event_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
		ctf_integer(cl_event_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetEventInfo(cl_event event, cl_event_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetEventInfo, event, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetEventInfo(event, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateUserEvent,

	TP_ARGS(
		cl_context, context,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
cl_event clCreateUserEvent(cl_context context, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clCreateUserEvent, context, errcode_ret);
	cl_event ret = reallib_clCreateUserEvent(context, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainEvent,

	TP_ARGS(
		cl_event, event
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
	)
)
cl_int clRetainEvent(cl_event event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainEvent, event);
	cl_int ret = reallib_clRetainEvent(event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseEvent,

	TP_ARGS(
		cl_event, event
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
	)
)
cl_int clReleaseEvent(cl_event event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseEvent, event);
	cl_int ret = reallib_clReleaseEvent(event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSetUserEventStatus,

	TP_ARGS(
		cl_event, event,
		cl_int, execution_status
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
		ctf_integer(cl_int, execution_status_field, execution_status)
	)
)
cl_int clSetUserEventStatus(cl_event event, cl_int execution_status)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clSetUserEventStatus, event, execution_status);
	cl_int ret = reallib_clSetUserEventStatus(event, execution_status);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSetEventCallback,

	TP_ARGS(
		cl_event, event,
		cl_int, command_exec_callback_type,
		void (CL_CALLBACK * )(cl_event, cl_int, void *), pfn_notify,
		void *, user_data
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
		ctf_integer(cl_int, command_exec_callback_type_field, command_exec_callback_type)
		ctf_integer(void (CL_CALLBACK * )(cl_event, cl_int, void *), pfn_notify_field, pfn_notify)
		ctf_integer(void *, user_data_field, user_data)
	)
)
cl_int clSetEventCallback(cl_event event, cl_int command_exec_callback_type, void (CL_CALLBACK * )(cl_event, cl_int, void *) pfn_notify, void * user_data)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clSetEventCallback, event, command_exec_callback_type, pfn_notify, user_data);
	cl_int ret = reallib_clSetEventCallback(event, command_exec_callback_type, pfn_notify, user_data);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetEventProfilingInfo,

	TP_ARGS(
		cl_event, event,
		cl_profiling_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
		ctf_integer(cl_profiling_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
cl_int clGetEventProfilingInfo(cl_event event, cl_profiling_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetEventProfilingInfo, event, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetEventProfilingInfo(event, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clFlush,

	TP_ARGS(
		cl_command_queue, command_queue
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
	)
)
cl_int clFlush(cl_command_queue command_queue)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clFlush, command_queue);
	cl_int ret = reallib_clFlush(command_queue);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clFinish,

	TP_ARGS(
		cl_command_queue, command_queue
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
	)
)
cl_int clFinish(cl_command_queue command_queue)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clFinish, command_queue);
	cl_int ret = reallib_clFinish(command_queue);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueReadBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		cl_bool, blocking_read,
		size_t, offset,
		size_t, size,
		void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_bool, blocking_read_field, blocking_read)
		ctf_integer(size_t, offset_field, offset)
		ctf_integer(size_t, size_field, size)
		ctf_integer(void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueReadBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, size_t offset, size_t size, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueReadBuffer, command_queue, buffer, blocking_read, offset, size, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueReadBuffer(command_queue, buffer, blocking_read, offset, size, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueReadBufferRect,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		cl_bool, blocking_read,
		const size_t *, buffer_offset,
		const size_t *, host_offset,
		const size_t *, region,
		size_t, buffer_row_pitch,
		size_t, buffer_slice_pitch,
		size_t, host_row_pitch,
		size_t, host_slice_pitch,
		void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_bool, blocking_read_field, blocking_read)
		ctf_integer(const size_t *, buffer_offset_field, buffer_offset)
		ctf_integer(const size_t *, host_offset_field, host_offset)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(size_t, buffer_row_pitch_field, buffer_row_pitch)
		ctf_integer(size_t, buffer_slice_pitch_field, buffer_slice_pitch)
		ctf_integer(size_t, host_row_pitch_field, host_row_pitch)
		ctf_integer(size_t, host_slice_pitch_field, host_slice_pitch)
		ctf_integer(void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueReadBufferRect(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, const size_t * buffer_offset, const size_t * host_offset, const size_t * region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clEnqueueReadBufferRect, command_queue, buffer, blocking_read, buffer_offset, host_offset, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueReadBufferRect(command_queue, buffer, blocking_read, buffer_offset, host_offset, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueWriteBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		cl_bool, blocking_write,
		size_t, offset,
		size_t, size,
		const void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_bool, blocking_write_field, blocking_write)
		ctf_integer(size_t, offset_field, offset)
		ctf_integer(size_t, size_field, size)
		ctf_integer(const void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueWriteBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, size_t offset, size_t size, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueWriteBuffer, command_queue, buffer, blocking_write, offset, size, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueWriteBuffer(command_queue, buffer, blocking_write, offset, size, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueWriteBufferRect,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		cl_bool, blocking_write,
		const size_t *, buffer_offset,
		const size_t *, host_offset,
		const size_t *, region,
		size_t, buffer_row_pitch,
		size_t, buffer_slice_pitch,
		size_t, host_row_pitch,
		size_t, host_slice_pitch,
		const void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_bool, blocking_write_field, blocking_write)
		ctf_integer(const size_t *, buffer_offset_field, buffer_offset)
		ctf_integer(const size_t *, host_offset_field, host_offset)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(size_t, buffer_row_pitch_field, buffer_row_pitch)
		ctf_integer(size_t, buffer_slice_pitch_field, buffer_slice_pitch)
		ctf_integer(size_t, host_row_pitch_field, host_row_pitch)
		ctf_integer(size_t, host_slice_pitch_field, host_slice_pitch)
		ctf_integer(const void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueWriteBufferRect(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, const size_t * buffer_offset, const size_t * host_offset, const size_t * region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clEnqueueWriteBufferRect, command_queue, buffer, blocking_write, buffer_offset, host_offset, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueWriteBufferRect(command_queue, buffer, blocking_write, buffer_offset, host_offset, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueFillBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		const void *, pattern,
		size_t, pattern_size,
		size_t, offset,
		size_t, size,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(const void *, pattern_field, pattern)
		ctf_integer(size_t, pattern_size_field, pattern_size)
		ctf_integer(size_t, offset_field, offset)
		ctf_integer(size_t, size_field, size)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueFillBuffer(cl_command_queue command_queue, cl_mem buffer, const void * pattern, size_t pattern_size, size_t offset, size_t size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clEnqueueFillBuffer, command_queue, buffer, pattern, pattern_size, offset, size, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueFillBuffer(command_queue, buffer, pattern, pattern_size, offset, size, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueCopyBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, src_buffer,
		cl_mem, dst_buffer,
		size_t, src_offset,
		size_t, dst_offset,
		size_t, size,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, src_buffer_field, src_buffer)
		ctf_integer(cl_mem, dst_buffer_field, dst_buffer)
		ctf_integer(size_t, src_offset_field, src_offset)
		ctf_integer(size_t, dst_offset_field, dst_offset)
		ctf_integer(size_t, size_field, size)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueCopyBuffer(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, size_t src_offset, size_t dst_offset, size_t size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueCopyBuffer, command_queue, src_buffer, dst_buffer, src_offset, dst_offset, size, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueCopyBuffer(command_queue, src_buffer, dst_buffer, src_offset, dst_offset, size, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueCopyBufferRect,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, src_buffer,
		cl_mem, dst_buffer,
		const size_t *, src_origin,
		const size_t *, dst_origin,
		const size_t *, region,
		size_t, src_row_pitch,
		size_t, src_slice_pitch,
		size_t, dst_row_pitch,
		size_t, dst_slice_pitch,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, src_buffer_field, src_buffer)
		ctf_integer(cl_mem, dst_buffer_field, dst_buffer)
		ctf_integer(const size_t *, src_origin_field, src_origin)
		ctf_integer(const size_t *, dst_origin_field, dst_origin)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(size_t, src_row_pitch_field, src_row_pitch)
		ctf_integer(size_t, src_slice_pitch_field, src_slice_pitch)
		ctf_integer(size_t, dst_row_pitch_field, dst_row_pitch)
		ctf_integer(size_t, dst_slice_pitch_field, dst_slice_pitch)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueCopyBufferRect(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, const size_t * src_origin, const size_t * dst_origin, const size_t * region, size_t src_row_pitch, size_t src_slice_pitch, size_t dst_row_pitch, size_t dst_slice_pitch, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clEnqueueCopyBufferRect, command_queue, src_buffer, dst_buffer, src_origin, dst_origin, region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueCopyBufferRect(command_queue, src_buffer, dst_buffer, src_origin, dst_origin, region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueReadImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, image,
		cl_bool, blocking_read,
		const size_t *, origin[3],
		const size_t *, region[3],
		size_t, row_pitch,
		size_t, slice_pitch,
		void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, image_field, image)
		ctf_integer(cl_bool, blocking_read_field, blocking_read)
		ctf_integer(const size_t *, origin[3]_field, origin[3])
		ctf_integer(const size_t *, region[3]_field, region[3])
		ctf_integer(size_t, row_pitch_field, row_pitch)
		ctf_integer(size_t, slice_pitch_field, slice_pitch)
		ctf_integer(void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueReadImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_read, const size_t * origin[3], const size_t * region[3], size_t row_pitch, size_t slice_pitch, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueReadImage, command_queue, image, blocking_read, origin[3], region[3], row_pitch, slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueReadImage(command_queue, image, blocking_read, origin[3], region[3], row_pitch, slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueWriteImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, image,
		cl_bool, blocking_write,
		const size_t *, origin[3],
		const size_t *, region[3],
		size_t, input_row_pitch,
		size_t, input_slice_pitch,
		const void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, image_field, image)
		ctf_integer(cl_bool, blocking_write_field, blocking_write)
		ctf_integer(const size_t *, origin[3]_field, origin[3])
		ctf_integer(const size_t *, region[3]_field, region[3])
		ctf_integer(size_t, input_row_pitch_field, input_row_pitch)
		ctf_integer(size_t, input_slice_pitch_field, input_slice_pitch)
		ctf_integer(const void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueWriteImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_write, const size_t * origin[3], const size_t * region[3], size_t input_row_pitch, size_t input_slice_pitch, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueWriteImage, command_queue, image, blocking_write, origin[3], region[3], input_row_pitch, input_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueWriteImage(command_queue, image, blocking_write, origin[3], region[3], input_row_pitch, input_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueFillImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, image,
		const void *, fill_color,
		const size_t *, origin[3],
		const size_t *, region[3],
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, image_field, image)
		ctf_integer(const void *, fill_color_field, fill_color)
		ctf_integer(const size_t *, origin[3]_field, origin[3])
		ctf_integer(const size_t *, region[3]_field, region[3])
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueFillImage(cl_command_queue command_queue, cl_mem image, const void * fill_color, const size_t * origin[3], const size_t * region[3], cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clEnqueueFillImage, command_queue, image, fill_color, origin[3], region[3], num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueFillImage(command_queue, image, fill_color, origin[3], region[3], num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueCopyImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, src_image,
		cl_mem, dst_image,
		const size_t *, src_origin[3],
		const size_t *, dst_origin[3],
		const size_t *, region[3],
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, src_image_field, src_image)
		ctf_integer(cl_mem, dst_image_field, dst_image)
		ctf_integer(const size_t *, src_origin[3]_field, src_origin[3])
		ctf_integer(const size_t *, dst_origin[3]_field, dst_origin[3])
		ctf_integer(const size_t *, region[3]_field, region[3])
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueCopyImage(cl_command_queue command_queue, cl_mem src_image, cl_mem dst_image, const size_t * src_origin[3], const size_t * dst_origin[3], const size_t * region[3], cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueCopyImage, command_queue, src_image, dst_image, src_origin[3], dst_origin[3], region[3], num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueCopyImage(command_queue, src_image, dst_image, src_origin[3], dst_origin[3], region[3], num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueCopyImageToBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, src_image,
		cl_mem, dst_buffer,
		const size_t *, src_origin[3],
		const size_t *, region[3],
		size_t, dst_offset,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, src_image_field, src_image)
		ctf_integer(cl_mem, dst_buffer_field, dst_buffer)
		ctf_integer(const size_t *, src_origin[3]_field, src_origin[3])
		ctf_integer(const size_t *, region[3]_field, region[3])
		ctf_integer(size_t, dst_offset_field, dst_offset)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueCopyImageToBuffer(cl_command_queue command_queue, cl_mem src_image, cl_mem dst_buffer, const size_t * src_origin[3], const size_t * region[3], size_t dst_offset, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueCopyImageToBuffer, command_queue, src_image, dst_buffer, src_origin[3], region[3], dst_offset, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueCopyImageToBuffer(command_queue, src_image, dst_buffer, src_origin[3], region[3], dst_offset, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueCopyBufferToImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, src_buffer,
		cl_mem, dst_image,
		size_t, src_offset,
		const size_t *, dst_origin[3],
		const size_t *, region[3],
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, src_buffer_field, src_buffer)
		ctf_integer(cl_mem, dst_image_field, dst_image)
		ctf_integer(size_t, src_offset_field, src_offset)
		ctf_integer(const size_t *, dst_origin[3]_field, dst_origin[3])
		ctf_integer(const size_t *, region[3]_field, region[3])
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueCopyBufferToImage(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_image, size_t src_offset, const size_t * dst_origin[3], const size_t * region[3], cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueCopyBufferToImage, command_queue, src_buffer, dst_image, src_offset, dst_origin[3], region[3], num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueCopyBufferToImage(command_queue, src_buffer, dst_image, src_offset, dst_origin[3], region[3], num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueMapBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		cl_bool, blocking_map,
		cl_map_flags, map_flags,
		size_t, offset,
		size_t, size,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_bool, blocking_map_field, blocking_map)
		ctf_integer(cl_map_flags, map_flags_field, map_flags)
		ctf_integer(size_t, offset_field, offset)
		ctf_integer(size_t, size_field, size)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
void * clEnqueueMapBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_map, cl_map_flags map_flags, size_t offset, size_t size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueMapBuffer, command_queue, buffer, blocking_map, map_flags, offset, size, num_events_in_wait_list, event_wait_list, event, errcode_ret);
	void * ret = reallib_clEnqueueMapBuffer(command_queue, buffer, blocking_map, map_flags, offset, size, num_events_in_wait_list, event_wait_list, event, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueMapImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, image,
		cl_bool, blocking_map,
		cl_map_flags, map_flags,
		const size_t *, origin[3],
		const size_t *, region[3],
		size_t *, image_row_pitch,
		size_t *, image_slice_pitch,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, image_field, image)
		ctf_integer(cl_bool, blocking_map_field, blocking_map)
		ctf_integer(cl_map_flags, map_flags_field, map_flags)
		ctf_integer(const size_t *, origin[3]_field, origin[3])
		ctf_integer(const size_t *, region[3]_field, region[3])
		ctf_integer(size_t *, image_row_pitch_field, image_row_pitch)
		ctf_integer(size_t *, image_slice_pitch_field, image_slice_pitch)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
void * clEnqueueMapImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_map, cl_map_flags map_flags, const size_t * origin[3], const size_t * region[3], size_t * image_row_pitch, size_t * image_slice_pitch, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueMapImage, command_queue, image, blocking_map, map_flags, origin[3], region[3], image_row_pitch, image_slice_pitch, num_events_in_wait_list, event_wait_list, event, errcode_ret);
	void * ret = reallib_clEnqueueMapImage(command_queue, image, blocking_map, map_flags, origin[3], region[3], image_row_pitch, image_slice_pitch, num_events_in_wait_list, event_wait_list, event, errcode_ret);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueUnmapMemObject,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, memobj,
		void *, mapped_ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, memobj_field, memobj)
		ctf_integer(void *, mapped_ptr_field, mapped_ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueUnmapMemObject(cl_command_queue command_queue, cl_mem memobj, void * mapped_ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueUnmapMemObject, command_queue, memobj, mapped_ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueUnmapMemObject(command_queue, memobj, mapped_ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueMigrateMemObjects,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_uint, num_mem_objects,
		const cl_mem *, mem_objects,
		cl_mem_migration_flags, flags,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_uint, num_mem_objects_field, num_mem_objects)
		ctf_integer(const cl_mem *, mem_objects_field, mem_objects)
		ctf_integer(cl_mem_migration_flags, flags_field, flags)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueMigrateMemObjects(cl_command_queue command_queue, cl_uint num_mem_objects, const cl_mem * mem_objects, cl_mem_migration_flags flags, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clEnqueueMigrateMemObjects, command_queue, num_mem_objects, mem_objects, flags, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueMigrateMemObjects(command_queue, num_mem_objects, mem_objects, flags, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueNDRangeKernel,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_kernel, kernel,
		cl_uint, work_dim,
		const size_t *, global_work_offset,
		const size_t *, global_work_size,
		const size_t *, local_work_size,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_uint, work_dim_field, work_dim)
		ctf_integer(const size_t *, global_work_offset_field, global_work_offset)
		ctf_integer(const size_t *, global_work_size_field, global_work_size)
		ctf_integer(const size_t *, local_work_size_field, local_work_size)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueNDRangeKernel(cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim, const size_t * global_work_offset, const size_t * global_work_size, const size_t * local_work_size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueNDRangeKernel, command_queue, kernel, work_dim, global_work_offset, global_work_size, local_work_size, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueNDRangeKernel(command_queue, kernel, work_dim, global_work_offset, global_work_size, local_work_size, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueNativeKernel,

	TP_ARGS(
		cl_command_queue, command_queue,
		void (CL_CALLBACK * )(void *), user_func,
		void *, args,
		size_t, cb_args,
		cl_uint, num_mem_objects,
		const cl_mem *, mem_list,
		const void **, args_mem_loc,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(void (CL_CALLBACK * )(void *), user_func_field, user_func)
		ctf_integer(void *, args_field, args)
		ctf_integer(size_t, cb_args_field, cb_args)
		ctf_integer(cl_uint, num_mem_objects_field, num_mem_objects)
		ctf_integer(const cl_mem *, mem_list_field, mem_list)
		ctf_integer(const void **, args_mem_loc_field, args_mem_loc)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueNativeKernel(cl_command_queue command_queue, void (CL_CALLBACK * )(void *) user_func, void * args, size_t cb_args, cl_uint num_mem_objects, const cl_mem * mem_list, const void ** args_mem_loc, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueNativeKernel, command_queue, user_func, args, cb_args, num_mem_objects, mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueNativeKernel(command_queue, user_func, args, cb_args, num_mem_objects, mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueMarkerWithWaitList,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueMarkerWithWaitList(cl_command_queue command_queue, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clEnqueueMarkerWithWaitList, command_queue, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueMarkerWithWaitList(command_queue, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueBarrierWithWaitList,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
cl_int clEnqueueBarrierWithWaitList(cl_command_queue command_queue, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_2 {
	tracepoint(clust_provider, clust_clEnqueueBarrierWithWaitList, command_queue, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueBarrierWithWaitList(command_queue, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueSVMFree,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_uint, num_svm_pointers
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_uint, num_svm_pointers_field, num_svm_pointers)
	)
)
cl_int clEnqueueSVMFree(cl_command_queue command_queue, cl_uint num_svm_pointers)  CL_API_SUFFIX__VERSION_2_0 {
	tracepoint(clust_provider, clust_clEnqueueSVMFree, command_queue, num_svm_pointers);
	cl_int ret = reallib_clEnqueueSVMFree(command_queue, num_svm_pointers);
	return ret;
}

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueSVMMemcpy,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_bool, blocking_copy,
		void *, dst_ptr,
		const void *, src_ptr,
		size_t, size,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field,