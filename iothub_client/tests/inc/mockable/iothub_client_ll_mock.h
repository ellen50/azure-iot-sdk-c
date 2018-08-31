// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

/** @file iothub_client_ll.h
*	@brief	 APIs that allow a user (usually a device) to communicate
*		     with an Azure IoTHub.
*
*	@details IoTHubClient_LL is a module that allows a user (usually a
*			 device) to communicate with an Azure IoTHub. It can send events
*			 and receive messages. At any given moment in time there can only
*			 be at most 1 message callback function.
*
*			 This API surface contains a set of APIs that allows the user to
*			 interact with the lower layer portion of the IoTHubClient. These APIs
*			 contain @c _LL_ in their name, but retain the same functionality like the
*			 @c IoTHubClient_... APIs, with one difference. If the @c _LL_ APIs are
*			 used then the user is responsible for scheduling when the actual work done
*			 by the IoTHubClient happens (when the data is sent/received on/from the wire).
*			 This is useful for constrained devices where spinning a separate thread is
*			 often not desired.
*/

#ifndef IOTHUB_CLIENT_LL_MOCK_H
#define IOTHUB_CLIENT_LL_MOCK_H

#ifdef __cplusplus
extern "C"
{
#endif

     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_LL_HANDLE, IoTHubClient_LL_CreateFromConnectionString, const char*, connectionString, IOTHUB_CLIENT_TRANSPORT_PROVIDER, protocol);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_LL_HANDLE, IoTHubClient_LL_Create, const IOTHUB_CLIENT_CONFIG*, config);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_LL_HANDLE, IoTHubClient_LL_CreateWithTransport, const IOTHUB_CLIENT_DEVICE_CONFIG*, config);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_LL_HANDLE, IoTHubClient_LL_CreateFromDeviceAuth, const char*, iothub_uri, const char*, device_id, IOTHUB_CLIENT_TRANSPORT_PROVIDER, protocol);
     MOCKABLE_FUNCTION(, void, IoTHubClient_LL_Destroy, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_SendEventAsync, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, IOTHUB_MESSAGE_HANDLE, eventMessageHandle, IOTHUB_CLIENT_EVENT_CONFIRMATION_CALLBACK, eventConfirmationCallback, void*, userContextCallback);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_GetSendStatus, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, IOTHUB_CLIENT_STATUS*, iotHubClientStatus);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_SetMessageCallback, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, IOTHUB_CLIENT_MESSAGE_CALLBACK_ASYNC, messageCallback, void*, userContextCallback);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_SetConnectionStatusCallback, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, IOTHUB_CLIENT_CONNECTION_STATUS_CALLBACK, connectionStatusCallback, void*, userContextCallback);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_SetRetryPolicy, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, IOTHUB_CLIENT_RETRY_POLICY, retryPolicy, size_t, retryTimeoutLimitInSeconds);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_GetRetryPolicy, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, IOTHUB_CLIENT_RETRY_POLICY*, retryPolicy, size_t*, retryTimeoutLimitInSeconds);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_GetLastMessageReceiveTime, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, time_t*, lastMessageReceiveTime);
     MOCKABLE_FUNCTION(, void, IoTHubClient_LL_DoWork, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_SetOption, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, const char*, optionName, const void*, value);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_SetDeviceTwinCallback, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, IOTHUB_CLIENT_DEVICE_TWIN_CALLBACK, deviceTwinCallback, void*, userContextCallback);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_SendReportedState, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, const unsigned char*, reportedState, size_t, size, IOTHUB_CLIENT_REPORTED_STATE_CALLBACK, reportedStateCallback, void*, userContextCallback);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_SetDeviceMethodCallback, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, IOTHUB_CLIENT_DEVICE_METHOD_CALLBACK_ASYNC, deviceMethodCallback, void*, userContextCallback);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_SetDeviceMethodCallback_Ex, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, IOTHUB_CLIENT_INBOUND_DEVICE_METHOD_CALLBACK, inboundDeviceMethodCallback, void*, userContextCallback);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_DeviceMethodResponse, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, METHOD_HANDLE, methodId, const unsigned char*, response, size_t, respSize, int, statusCode);

#ifndef DONT_USE_UPLOADTOBLOB
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_UploadToBlob, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, const char*, destinationFileName, const unsigned char*, source, size_t, size);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_UploadMultipleBlocksToBlob, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, const char*, destinationFileName, IOTHUB_CLIENT_FILE_UPLOAD_GET_DATA_CALLBACK, getDataCallback, void*, context);
     MOCKABLE_FUNCTION(, IOTHUB_CLIENT_RESULT, IoTHubClient_LL_UploadMultipleBlocksToBlobEx, IOTHUB_CLIENT_LL_HANDLE, iotHubClientHandle, const char*, destinationFileName, IOTHUB_CLIENT_FILE_UPLOAD_GET_DATA_CALLBACK_EX, getDataCallbackEx, void*, context);
#endif /*DONT_USE_UPLOADTOBLOB*/

#ifdef __cplusplus
}
#endif

#endif /* IOTHUB_CLIENT_LL_MOCK_H */
