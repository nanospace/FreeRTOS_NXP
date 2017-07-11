var group__sdif =
[
    [ "sdif_dma_descriptor_t", "group__sdif.html#structsdif__dma__descriptor__t", [
      [ "dmaDesAttribute", "group__sdif.html#a72df1080eed9741f48b965ad711320d9", null ],
      [ "dmaDataBufferSize", "group__sdif.html#a790531f1ac8de41aefeb96c46a5d92c0", null ],
      [ "dmaDataBufferAddr0", "group__sdif.html#a9a924153e564b2677888e42b6e7cc0e0", null ],
      [ "dmaDataBufferAddr1", "group__sdif.html#a4d21898bbfbcd9c365158007df1aab05", null ]
    ] ],
    [ "sdif_dma_config_t", "group__sdif.html#structsdif__dma__config__t", [
      [ "enableFixBurstLen", "group__sdif.html#a667f6adec697658462b38ee4bed1072b", null ],
      [ "mode", "group__sdif.html#a345ab2eb2db45c8063c0df1a2e17e184", null ],
      [ "dmaDesSkipLen", "group__sdif.html#a45f0984a70d7c965cb5a99466ad3b3c2", null ],
      [ "dmaDesBufferStartAddr", "group__sdif.html#ae45573eaf3c30851628c418beaa61082", null ],
      [ "dmaDesBufferLen", "group__sdif.html#ad8df70e9eefadf332d7d533944184aa2", null ]
    ] ],
    [ "sdif_data_t", "group__sdif.html#structsdif__data__t", [
      [ "streamTransfer", "group__sdif.html#a45919dd5b99a12fde0533e4ed4eaee23", null ],
      [ "enableAutoCommand12", "group__sdif.html#a384b40e7335eccf46383a63ddfdea32c", null ],
      [ "enableIgnoreError", "group__sdif.html#a0224fbbfecf1081cf5fa8d938c1c0a6f", null ],
      [ "blockSize", "group__sdif.html#aaad33a25ee163627fcb8e541f4b90dd2", null ],
      [ "blockCount", "group__sdif.html#a3373dee9ec2aa0e234e4e326c7464563", null ],
      [ "rxData", "group__sdif.html#acfabbd4ffaaaee0d23065b5ca1efa886", null ],
      [ "txData", "group__sdif.html#a4758c7e956f0f861f6d1e28e8283b8cf", null ]
    ] ],
    [ "sdif_command_t", "group__sdif.html#structsdif__command__t", [
      [ "index", "group__sdif.html#a8fe4e592bad55bc9bf76987f52c7ed35", null ],
      [ "argument", "group__sdif.html#a37d3f9c4d6e34705704f17d17cd7c3ab", null ],
      [ "response", "group__sdif.html#a3bc6833d58fb2bc9d1b0c7b1441f80ad", null ],
      [ "type", "group__sdif.html#ade8a7d7009b8b006d7dc9aa01b5eb202", null ],
      [ "responseType", "group__sdif.html#ab960752c120de7b8ea7037d25885054b", null ],
      [ "flags", "group__sdif.html#a0375b0728fb6e1c16202b14fb88370e4", null ],
      [ "responseErrorFlags", "group__sdif.html#a53f11af056646ba291a0944ad5a2c35a", null ]
    ] ],
    [ "sdif_transfer_t", "group__sdif.html#structsdif__transfer__t", [
      [ "data", "group__sdif.html#a6863126afdc549b3d88db925fe1b1105", null ],
      [ "command", "group__sdif.html#ad8cef8ffa09908cf41de9aabfcdb5f7d", null ]
    ] ],
    [ "sdif_config_t", "group__sdif.html#structsdif__config__t", [
      [ "responseTimeout", "group__sdif.html#a75e56acaadd7e9911dd6962c606729f1", null ],
      [ "cardDetDebounce_Clock", "group__sdif.html#a4c8c1b3a40de5d4afeba1f2d7f546709", null ],
      [ "endianMode", "group__sdif.html#a765887f8144b1b3e49d398efcc6963f4", null ],
      [ "dataTimeout", "group__sdif.html#a51d64cf44adc209c94321bf287624693", null ]
    ] ],
    [ "sdif_capability_t", "group__sdif.html#structsdif__capability__t", [
      [ "sdVersion", "group__sdif.html#a11d7351d9cc2c1ca3deea72469332d5b", null ],
      [ "mmcVersion", "group__sdif.html#a5460bf17f4afa3b9be5ae0cbd85b9844", null ],
      [ "maxBlockLength", "group__sdif.html#ac90d0dc98eeaf298be167457460612c5", null ],
      [ "maxBlockCount", "group__sdif.html#a3506212f492bb1245325f525c58764be", null ],
      [ "flags", "group__sdif.html#a7a5be0455c2b6a01ede3b11d4ff38f26", null ]
    ] ],
    [ "sdif_transfer_callback_t", "group__sdif.html#structsdif__transfer__callback__t", [
      [ "SDIOInterrupt", "group__sdif.html#a2fca6516694e15f850094ecd4fc4c6da", null ],
      [ "DMADesUnavailable", "group__sdif.html#a94440a7519702fe40b88ff7d3ab32f49", null ],
      [ "CommandReload", "group__sdif.html#a44cbdc09bf8352c1edf6c68c4231344c", null ],
      [ "TransferComplete", "group__sdif.html#ad9e6c00c0b48fe8ee8cd164078c90719", null ]
    ] ],
    [ "sdif_handle_t", "group__sdif.html#structsdif__handle__t", [
      [ "data", "group__sdif.html#af9567067c6a890daf7ce93115dc07162", null ],
      [ "command", "group__sdif.html#ab0ee4fe56f4d2efcc2df47ecc18bea67", null ],
      [ "interruptFlags", "group__sdif.html#aff81b430f9f653d5953998c040ea8d33", null ],
      [ "dmaInterruptFlags", "group__sdif.html#a72555f99e1964868ec0c266b36e5c8f4", null ],
      [ "transferredWords", "group__sdif.html#a434394945439505fdaf0c204032a2e24", null ],
      [ "callback", "group__sdif.html#ac82afb46214ddd149a603528f159000f", null ],
      [ "userData", "group__sdif.html#a35406f0c9bea4fa5c4add50a192c856b", null ]
    ] ],
    [ "sdif_host_t", "group__sdif.html#structsdif__host__t", [
      [ "base", "group__sdif.html#abd4cbcb1517ce0a56cacc652d6a824a4", null ],
      [ "sourceClock_Hz", "group__sdif.html#a156b17a08b203e29c9856b7e27e8bd1d", null ],
      [ "config", "group__sdif.html#a362c18173753dcbffcf27bda2a856adc", null ],
      [ "transfer", "group__sdif.html#a7824284bd039e97f492c05632db174d4", null ],
      [ "capability", "group__sdif.html#aeabf67943f149843432767b89e929156", null ]
    ] ],
    [ "FSL_SDIF_DRIVER_VERSION", "group__sdif.html#ga881d73082e5a2fb426c8fdd98d077e8e", null ],
    [ "SDIF_DriverIRQHandler", "group__sdif.html#ga259cc262e84685e2963e7affb50f2bae", null ],
    [ "SDIF_SUPPORT_SD_VERSION", "group__sdif.html#gaddacfad0e8db5a70d64f9113c0c0481f", null ],
    [ "SDIF_SUPPORT_MMC_VERSION", "group__sdif.html#ga3e811f1cf00ade81c4092cfd697fcb90", null ],
    [ "SDIF_TIMEOUT_VALUE", "group__sdif.html#ga25cd560833ec7ad8a18f878a550fb521", null ],
    [ "SDIF_POLL_DEMAND_VALUE", "group__sdif.html#gacdd4ac4932b0ba61696c09f819ba3df1", null ],
    [ "SDIF_DMA_DESCRIPTOR_BUFFER1_SIZE", "group__sdif.html#ga1036515c95a5913819de41cc09a55022", null ],
    [ "SDIF_DMA_DESCRIPTOR_BUFFER2_SIZE", "group__sdif.html#gab8dd70f4693a15793ee9ebbd5927a464", null ],
    [ "SDIF_RX_WATERMARK", "group__sdif.html#ga8f069c802fc3f5901e3352a794e4bac2", null ],
    [ "SDIF_TX_WATERMARK", "group__sdif.html#gafb44679a0ba81e9805276d29f97d388e", null ],
    [ "SDIF_INDENTIFICATION_MODE_SAMPLE_DELAY", "group__sdif.html#ga062af6ab1f383b1ceaf1f3aab89aef1d", null ],
    [ "sdif_transfer_function_t", "group__sdif.html#ga24f457e1fc3ee1d874b8174efd5d554b", null ],
    [ "_sdif_status", "group__sdif.html#gacf64d5a22f338dd7c044883fb9f6beea", [
      [ "kStatus_SDIF_DescriptorBufferLenError", "group__sdif.html#ggacf64d5a22f338dd7c044883fb9f6beeaaffb9182360cf683b9b56bb7d6137f1fa", null ],
      [ "kStatue_SDIF_InvalidArgument", "group__sdif.html#ggacf64d5a22f338dd7c044883fb9f6beeaaebf50dd53179a313650faea0a0c58a36", null ],
      [ "kStatus_SDIF_SyncCmdTimeout", "group__sdif.html#ggacf64d5a22f338dd7c044883fb9f6beeaa768343b1047ef305d1f6d4890dc2f6e8", null ]
    ] ],
    [ "_sdif_capability_flag", "group__sdif.html#ga988950ca8b81d6f1e72bb45d163b2b2e", [
      [ "kSDIF_SupportHighSpeedFlag", "group__sdif.html#gga988950ca8b81d6f1e72bb45d163b2b2ea37d71dded0a8486f1903bf9d388d0f19", null ],
      [ "kSDIF_SupportDmaFlag", "group__sdif.html#gga988950ca8b81d6f1e72bb45d163b2b2ea5e195eba807f307e481e5e650eb3aed7", null ],
      [ "kSDIF_SupportSuspendResumeFlag", "group__sdif.html#gga988950ca8b81d6f1e72bb45d163b2b2ea8d919e7879aa3cb1dd653233ca804d8f", null ],
      [ "kSDIF_SupportV330Flag", "group__sdif.html#gga988950ca8b81d6f1e72bb45d163b2b2ea7f35069105bd14ef049563536cb26ebb", null ],
      [ "kSDIF_Support4BitFlag", "group__sdif.html#gga988950ca8b81d6f1e72bb45d163b2b2ea85bd0f974c1db6fbb3e9ff905c5ced33", null ],
      [ "kSDIF_Support8BitFlag", "group__sdif.html#gga988950ca8b81d6f1e72bb45d163b2b2eac3e1e0c96d0a6d6a3fdf004d3306bae4", null ]
    ] ],
    [ "_sdif_reset_type", "group__sdif.html#gadab31b8f99a2f37da651f7d42eec1ef3", [
      [ "kSDIF_ResetController", "group__sdif.html#ggadab31b8f99a2f37da651f7d42eec1ef3aef40cc6fcf0a97b4b2fd2c75f88bc779", null ],
      [ "kSDIF_ResetFIFO", "group__sdif.html#ggadab31b8f99a2f37da651f7d42eec1ef3ac0fb2455d783502198e25620759737e6", null ],
      [ "kSDIF_ResetDMAInterface", "group__sdif.html#ggadab31b8f99a2f37da651f7d42eec1ef3a9200d7f30ecc3222473158089913bd3a", null ],
      [ "kSDIF_ResetAll", "group__sdif.html#ggadab31b8f99a2f37da651f7d42eec1ef3a1e49461e4d4843585850d067d207d582", null ]
    ] ],
    [ "sdif_bus_width_t", "group__sdif.html#gab34cef4fa3bca559d3b65ec55e02a819", [
      [ "kSDIF_Bus1BitWidth", "group__sdif.html#ggab34cef4fa3bca559d3b65ec55e02a819ab7d8da1ba7af8502355e546b5f086ed2", null ],
      [ "kSDIF_Bus4BitWidth", "group__sdif.html#ggab34cef4fa3bca559d3b65ec55e02a819a1baf3ad61dd63b12c5d89df87ae58fea", null ],
      [ "kSDIF_Bus8BitWidth", "group__sdif.html#ggab34cef4fa3bca559d3b65ec55e02a819af919b8fe0e8e5531cb62ad00a7135d6b", null ]
    ] ],
    [ "_sdif_command_flags", "group__sdif.html#gaa1ff9670f85b8608b00e7de5bd9ed42b", [
      [ "kSDIF_CmdResponseExpect", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba69b983ebdb8a3e9417e1448d9e257772", null ],
      [ "kSDIF_CmdResponseLengthLong", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba7881b17a0812647bf1211bd6c2ecbacd", null ],
      [ "kSDIF_CmdCheckResponseCRC", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba60b2fc9d9d799ce1a402feb88ad1d0f7", null ],
      [ "kSDIF_DataExpect", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42bafaca694830ba3659fc5f4ab0c54727ce", null ],
      [ "kSDIF_DataWriteToCard", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba1d8afe6680f1803f334c6242595636ac", null ],
      [ "kSDIF_DataStreamTransfer", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42bae63bc8f0de5089a3f50fcd881f42b222", null ],
      [ "kSDIF_DataTransferAutoStop", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba7b124728d0045868bd9ee09da3cdab07", null ],
      [ "kSDIF_WaitPreTransferComplete", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42bafec895df86c912894df96ed10958a521", null ],
      [ "kSDIF_TransferStopAbort", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba94065d24edd9a7668a66dc9bd591950a", null ],
      [ "kSDIF_SendInitialization", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba9fb7d6c27a3fcd251d4fe32ec4840480", null ],
      [ "kSDIF_CmdUpdateClockRegisterOnly", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42baa4c4bf9a08b7e29d4847753f9b16ad17", null ],
      [ "kSDIF_CmdtoReadCEATADevice", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba093f1056ae474c3e6c0fbc50794b4cdf", null ],
      [ "kSDIF_CmdExpectCCS", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba1565e1a4e13a968d157f9262381bb5c7", null ],
      [ "kSDIF_BootModeEnable", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42bae80eb10284249894dce0ab1858fe733f", null ],
      [ "kSDIF_BootModeExpectAck", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42bae82a77a4612cab23fd02d796dd92e319", null ],
      [ "kSDIF_BootModeDisable", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42bad7f0a31bd66b1494e9c0bf2859f1628d", null ],
      [ "kSDIF_BootModeAlternate", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42bae06160be54c46c5f69e9c0eedf381270", null ],
      [ "kSDIF_CmdVoltageSwitch", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba33079fbf59cf33517c65161da234bade", null ],
      [ "kSDIF_CmdDataUseHoldReg", "group__sdif.html#ggaa1ff9670f85b8608b00e7de5bd9ed42ba6b5255fe7e86c08e16ce8d007910fe59", null ]
    ] ],
    [ "_sdif_command_type", "group__sdif.html#ga70f9239a5bbc7b4f58c5de7c24d75259", [
      [ "kCARD_CommandTypeNormal", "group__sdif.html#gga70f9239a5bbc7b4f58c5de7c24d75259ae24ab83bd6c0959918366bee522417f9", null ],
      [ "kCARD_CommandTypeSuspend", "group__sdif.html#gga70f9239a5bbc7b4f58c5de7c24d75259a635a0b0c8ce3312236ca7a2d1ce159f5", null ],
      [ "kCARD_CommandTypeResume", "group__sdif.html#gga70f9239a5bbc7b4f58c5de7c24d75259a5c6154a2bf09464d521d21c874fc76a7", null ],
      [ "kCARD_CommandTypeAbort", "group__sdif.html#gga70f9239a5bbc7b4f58c5de7c24d75259aa3909c9f96f6ec9fa625efe84ecfb5c9", null ]
    ] ],
    [ "_sdif_response_type", "group__sdif.html#ga70b595ea95fab1b1dc7f2d158149f058", [
      [ "kCARD_ResponseTypeNone", "group__sdif.html#gga70b595ea95fab1b1dc7f2d158149f058a5d49d4b2f8a98053ee48d5012acf9ed2", null ],
      [ "kCARD_ResponseTypeR1", "group__sdif.html#gga70b595ea95fab1b1dc7f2d158149f058a74964391f7a0126c628c74baeafa518b", null ],
      [ "kCARD_ResponseTypeR1b", "group__sdif.html#gga70b595ea95fab1b1dc7f2d158149f058a7e8a8155761b6f1511f498ce53e07ccf", null ],
      [ "kCARD_ResponseTypeR2", "group__sdif.html#gga70b595ea95fab1b1dc7f2d158149f058ac4895a8c8ba120c3732db68b89f96953", null ],
      [ "kCARD_ResponseTypeR3", "group__sdif.html#gga70b595ea95fab1b1dc7f2d158149f058ad1f920acb2d8a5a28bff976cae7aff46", null ],
      [ "kCARD_ResponseTypeR4", "group__sdif.html#gga70b595ea95fab1b1dc7f2d158149f058a8298df9537021d76ecfe0a026c4c3fdd", null ],
      [ "kCARD_ResponseTypeR5", "group__sdif.html#gga70b595ea95fab1b1dc7f2d158149f058a9c1b4e62f3f81d7d23ec127c3a4a213f", null ],
      [ "kCARD_ResponseTypeR5b", "group__sdif.html#gga70b595ea95fab1b1dc7f2d158149f058ae08443bb563fccdaba2fc81737292fb1", null ],
      [ "kCARD_ResponseTypeR6", "group__sdif.html#gga70b595ea95fab1b1dc7f2d158149f058a1a659f655dbc1e029fd601f496e81bb5", null ],
      [ "kCARD_ResponseTypeR7", "group__sdif.html#gga70b595ea95fab1b1dc7f2d158149f058a3e8c6d2dc60235e4134e3a46789bebd1", null ]
    ] ],
    [ "_sdif_interrupt_mask", "group__sdif.html#ga0e96eadb9c93f698f162073edb1f9ac7", [
      [ "kSDIF_CardDetect", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a160a4abad8284aacf4126987ee59324d", null ],
      [ "kSDIF_ResponseError", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a6a8baea81c15a887cee8d76593721754", null ],
      [ "kSDIF_CommandDone", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a7aab46ff287bade786f734825bf19e6a", null ],
      [ "kSDIF_DataTransferOver", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7ab0a446850d226e415aaf9f76672e87e4", null ],
      [ "kSDIF_WriteFIFORequest", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a0ed53d5087e02de21a39b0952fa43a9f", null ],
      [ "kSDIF_ReadFIFORequest", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7aaa8b0faf4e56e6f8b4aeb00124fb6cf4", null ],
      [ "kSDIF_ResponseCRCError", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a67f0464831371026d510e171008bbb18", null ],
      [ "kSDIF_DataCRCError", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7ac487eb08c6910e398eb303b75bcd29a0", null ],
      [ "kSDIF_ResponseTimeout", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a619f95afb5a0dddf955517eff94b3939", null ],
      [ "kSDIF_DataReadTimeout", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7aa323878dfaffad951258dda2357f2e68", null ],
      [ "kSDIF_DataStarvationByHostTimeout", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7afad89a62d07fba9b26fe6ab7ddba2bf3", null ],
      [ "kSDIF_FIFOError", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a397e10660d40bb20969df3b7699db4f2", null ],
      [ "kSDIF_HardwareLockError", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a761428cb616af48531af3f857d9e0be5", null ],
      [ "kSDIF_DataStartBitError", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a291b8c9bbb1d9e989545d6d61af08117", null ],
      [ "kSDIF_AutoCmdDone", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7aa52598ea2150e99c45c7b9924ad4fd94", null ],
      [ "kSDIF_DataEndBitError", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a2bac7769b6e2c2290630a9fef6f6d7c8", null ],
      [ "kSDIF_SDIOInterrupt", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a0b9a6053102bd4b4b35df1442223281d", null ],
      [ "kSDIF_CommandTransferStatus", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a0ca5490df2a1d065d7ad41f576163104", null ],
      [ "kSDIF_DataTransferStatus", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a052aab1aca6b295d572adc9cb61f7561", null ],
      [ "kSDIF_AllInterruptStatus", "group__sdif.html#gga0e96eadb9c93f698f162073edb1f9ac7a2bdef2ae7a84e31cd7ad50ec3f24b04b", null ]
    ] ],
    [ "_sdif_dma_status", "group__sdif.html#ga4d5ca39e440e93395dc6dcf08d34dda4", [
      [ "kSDIF_DMATransFinishOneDescriptor", "group__sdif.html#gga4d5ca39e440e93395dc6dcf08d34dda4ac0d13081e45441059e860a377129398a", null ],
      [ "kSDIF_DMARecvFinishOneDescriptor", "group__sdif.html#gga4d5ca39e440e93395dc6dcf08d34dda4aad0130645ec9d3b61d4aa370b22dd69d", null ],
      [ "kSDIF_DMAFatalBusError", "group__sdif.html#gga4d5ca39e440e93395dc6dcf08d34dda4aa622d870a3753fd81ddeb07d52b9472c", null ],
      [ "kSDIF_DMADescriptorUnavailable", "group__sdif.html#gga4d5ca39e440e93395dc6dcf08d34dda4acde9409865d8c3541694543672f7398e", null ],
      [ "kSDIF_DMACardErrorSummary", "group__sdif.html#gga4d5ca39e440e93395dc6dcf08d34dda4a8851cf5387f9071b392fc50faf9fbd90", null ],
      [ "kSDIF_NormalInterruptSummary", "group__sdif.html#gga4d5ca39e440e93395dc6dcf08d34dda4a844f5f23ed367ff3959d529c03c545a4", null ],
      [ "kSDIF_AbnormalInterruptSummary", "group__sdif.html#gga4d5ca39e440e93395dc6dcf08d34dda4a2f91f26a38f52241a995d2bd90bd8ac2", null ]
    ] ],
    [ "_sdif_dma_descriptor_flag", "group__sdif.html#gacd315cd72238eeab65497fbf3f50013f", [
      [ "kSDIF_DisableCompleteInterrupt", "group__sdif.html#ggacd315cd72238eeab65497fbf3f50013fa1c2af2525d1f81757b7da07eda13df16", null ],
      [ "kSDIF_DMADescriptorDataBufferEnd", "group__sdif.html#ggacd315cd72238eeab65497fbf3f50013fa35d7873e7234b6f6a8dd60f83d6a1576", null ],
      [ "kSDIF_DMADescriptorDataBufferStart", "group__sdif.html#ggacd315cd72238eeab65497fbf3f50013faa98e2d5b42b28b1c4bebe29ceb48b041", null ],
      [ "kSDIF_DMASecondAddrChained", "group__sdif.html#ggacd315cd72238eeab65497fbf3f50013fa69a7866e867cc6b241fdabac6941f559", null ],
      [ "kSDIF_DMADescriptorEnd", "group__sdif.html#ggacd315cd72238eeab65497fbf3f50013fade67ea0cc618f38d8a6c0e6a87995994", null ],
      [ "kSDIF_DMADescriptorOwnByDMA", "group__sdif.html#ggacd315cd72238eeab65497fbf3f50013fa1e1368354275b6dd092bc91a1cec781d", null ]
    ] ],
    [ "sdif_dma_mode_t", "group__sdif.html#gad23d130b4983cde4e50a6b0526af7ef5", null ],
    [ "_sdif_card_freq", "group__sdif.html#ga33d3ba2228bd8dc859225dca788a8d8e", [
      [ "kSDIF_Freq50MHZ", "group__sdif.html#gga33d3ba2228bd8dc859225dca788a8d8ea7a18d5e4a66bf3c51b23ffa251949743", null ],
      [ "kSDIF_Freq400KHZ", "group__sdif.html#gga33d3ba2228bd8dc859225dca788a8d8ea92769b11ca8499116ef6008265368439", null ]
    ] ],
    [ "_sdif_clock_pharse_shift", "group__sdif.html#ga828f02c8a9326350ca1702a29e75229d", [
      [ "kSDIF_ClcokPharseShift0", "group__sdif.html#gga828f02c8a9326350ca1702a29e75229da954f5555e77eae2d79ef6d9109d997e9", null ],
      [ "kSDIF_ClcokPharseShift90", "group__sdif.html#gga828f02c8a9326350ca1702a29e75229dae4af9853e9fab036914b28ac4ea3d518", null ],
      [ "kSDIF_ClcokPharseShift180", "group__sdif.html#gga828f02c8a9326350ca1702a29e75229daaa9f2a16e15a67ce6fc277452f514ed9", null ],
      [ "kSDIF_ClcokPharseShift270", "group__sdif.html#gga828f02c8a9326350ca1702a29e75229da7ab8e41fdcd0481c50c8fb1844641c8a", null ]
    ] ],
    [ "SDIF_Init", "group__sdif.html#gaf3d376ef4ebd49d0a194187b9e3fda25", null ],
    [ "SDIF_Deinit", "group__sdif.html#ga44ffb4c05d4f35ff83d120f0d4eadd10", null ],
    [ "SDIF_SendCardActive", "group__sdif.html#ga0520bc2d303de664527ca056d12b8dd7", null ],
    [ "SDIF_DetectCardInsert", "group__sdif.html#gab1e2eea6244cdc8f2438a3f0d2f09b3a", null ],
    [ "SDIF_EnableCardClock", "group__sdif.html#ga238fba84ef11ca7606a17024d46099d3", null ],
    [ "SDIF_EnableLowPowerMode", "group__sdif.html#ga731675f9cc243f93b5bee3f00f676fba", null ],
    [ "SDIF_SetCardClock", "group__sdif.html#ga052694c07f58b318c661ea18b3c1890a", null ],
    [ "SDIF_Reset", "group__sdif.html#gad53fbc5b77f2b99d11a085b22592ede0", null ],
    [ "SDIF_EnableCardPower", "group__sdif.html#ga29e9a4d679c626c3c09d701252d3944a", null ],
    [ "SDIF_GetCardWriteProtect", "group__sdif.html#gabbad56ab4fcf4b10f63d37c78ca2ce9c", null ],
    [ "SDIF_SetCardBusWidth", "group__sdif.html#ga5ba801459f26d5737036a09f56906ca9", null ],
    [ "SDIF_AssertHardwareReset", "group__sdif.html#gaa64572819b17cb8ab2e0f9e4d1e58079", null ],
    [ "SDIF_SendCommand", "group__sdif.html#ga1871b7bc4a8845121e3e3c5ec71e9ff6", null ],
    [ "SDIF_EnableGlobalInterrupt", "group__sdif.html#ga4df0d246442af9b0980059c413034ba0", null ],
    [ "SDIF_EnableInterrupt", "group__sdif.html#ga9f5e2107a7313f59ea9ee93826d1814e", null ],
    [ "SDIF_DisableInterrupt", "group__sdif.html#ga82b9d1520698894b52b8e0fc7eb917db", null ],
    [ "SDIF_GetInterruptStatus", "group__sdif.html#ga4d35b808d8b0ee949f1358b7807d8e29", null ],
    [ "SDIF_ClearInterruptStatus", "group__sdif.html#ga591a0ea1e778d01a4fcc45b2e5c8fade", null ],
    [ "SDIF_TransferCreateHandle", "group__sdif.html#gada2c95bc61cf25f0d49fc7daa09fe4a1", null ],
    [ "SDIF_EnableDmaInterrupt", "group__sdif.html#ga853b2efb18cbddb0544cd973c975107f", null ],
    [ "SDIF_DisableDmaInterrupt", "group__sdif.html#gacc05b4f10da3d87c7b8d5e33fd21a0b2", null ],
    [ "SDIF_GetInternalDMAStatus", "group__sdif.html#ga3a02a30d2f6c5e4031ccba7bdbaf4ff2", null ],
    [ "SDIF_ClearInternalDMAStatus", "group__sdif.html#ga9ecc4486134980e1bd0f88f8ad49bd6f", null ],
    [ "SDIF_InternalDMAConfig", "group__sdif.html#gada1c8bc16d487ab726e71f621f8b48fe", null ],
    [ "SDIF_SendReadWait", "group__sdif.html#gac7ed837df2405c44bcdb6d777581884f", null ],
    [ "SDIF_AbortReadData", "group__sdif.html#ga3b0acc99a40a2992041d8628b733027c", null ],
    [ "SDIF_EnableCEATAInterrupt", "group__sdif.html#ga1e7e5df36b8ef27cf047dadfd7d96a14", null ],
    [ "SDIF_TransferNonBlocking", "group__sdif.html#gaf37227d56a5b14d21b9d6d75566c6aac", null ],
    [ "SDIF_TransferBlocking", "group__sdif.html#ga864c001cda8f456e8fd9eecca2492c66", null ],
    [ "SDIF_ReleaseDMADescriptor", "group__sdif.html#ga9a8a07fe13db8c3d090fc8c16f5116e0", null ],
    [ "SDIF_GetCapability", "group__sdif.html#ga7328c849a897a65bc5379a1e95a7669d", null ],
    [ "SDIF_GetControllerStatus", "group__sdif.html#ga66ea0d4a73b9f4961437a5d9c9727bfa", null ],
    [ "SDIF_SendCCSD", "group__sdif.html#ga3f50e2a3a43c7f9fe7a95cc2a65c26d3", null ],
    [ "SDIF_ConfigClockDelay", "group__sdif.html#gabb1f2a73fbc1a47f0f3d3f19f7179f62", null ]
];