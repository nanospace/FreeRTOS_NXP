var group__lpc__enet =
[
    [ "enet_rx_bd_struct_t", "group__lpc__enet.html#structenet__rx__bd__struct__t", [
      [ "buff1Addr", "group__lpc__enet.html#a881f1deac35ce5d5f9719d3d18a0af8b", null ],
      [ "reserved", "group__lpc__enet.html#a60a532ee3fd7b5a298b657d44eff4b9c", null ],
      [ "buff2Addr", "group__lpc__enet.html#a3db14cbe922895a04a6afe2c859c9951", null ],
      [ "control", "group__lpc__enet.html#add9990c8d0dce546e9a11475ebfad44b", null ]
    ] ],
    [ "enet_tx_bd_struct_t", "group__lpc__enet.html#structenet__tx__bd__struct__t", [
      [ "buff1Addr", "group__lpc__enet.html#a0454f58cca6e2e24f2dfd4684f135190", null ],
      [ "buff2Addr", "group__lpc__enet.html#a77233cda60aae4ed7c152759f808e876", null ],
      [ "buffLen", "group__lpc__enet.html#afc185d0272089a9715ce26de9323e652", null ],
      [ "controlStat", "group__lpc__enet.html#a8c9a5640d210d18067c77a91d6202471", null ]
    ] ],
    [ "enet_buffer_config_t", "group__lpc__enet.html#structenet__buffer__config__t", [
      [ "rxRingLen", "group__lpc__enet.html#a9bb80bbb6e1978438e35e0f711fce518", null ],
      [ "txRingLen", "group__lpc__enet.html#acdbe8e9322206694dcaf80275e697415", null ],
      [ "txDescStartAddrAlign", "group__lpc__enet.html#a3399f58d5357ce7afa38dd1539cffc31", null ],
      [ "txDescTailAddrAlign", "group__lpc__enet.html#a0f2363dd465d238cd4000a6d0bb9f5b8", null ],
      [ "rxDescStartAddrAlign", "group__lpc__enet.html#ab4b47626a25952119e9cccc4dcbfa779", null ],
      [ "rxDescTailAddrAlign", "group__lpc__enet.html#af4569c27d3ce18155a1d2a4d839be98a", null ],
      [ "rxBufferStartAddr", "group__lpc__enet.html#a03f57fe30845e24c2a80ec70703dd040", null ],
      [ "rxBuffSizeAlign", "group__lpc__enet.html#a01edfb2c2441e18da8cf716c9104ef88", null ]
    ] ],
    [ "enet_multiqueue_config_t", "group__lpc__enet.html#structenet__multiqueue__config__t", [
      [ "dmaTxSche", "group__lpc__enet.html#adb3c693c31f46287e875be57c70efbb4", null ],
      [ "burstLen", "group__lpc__enet.html#a3293ceb8c81b28acda54fd101e75fdd0", null ],
      [ "txdmaChnWeight", "group__lpc__enet.html#a27eefbae2afc6f55f7b502dac50de82f", null ],
      [ "mtltxSche", "group__lpc__enet.html#ae367eb599753c362a464ef5e7fc84a60", null ],
      [ "mtlrxSche", "group__lpc__enet.html#a2c822e18ea2cccf9e094343196bc68cf", null ],
      [ "rxqueweight", "group__lpc__enet.html#a456161b0a2c9cefa4b32fdbd48442c42", null ],
      [ "txqueweight", "group__lpc__enet.html#a156015baa1717b065c8a6ad6fbc4051c", null ],
      [ "rxqueuePrio", "group__lpc__enet.html#a03a1a8d3d58794956f1d5cede486d589", null ],
      [ "txqueuePrio", "group__lpc__enet.html#aff070de5c97d2c1c5e23af12a999057b", null ],
      [ "mtlrxQuemap", "group__lpc__enet.html#aedd893559c0da722f6154d72beae607d", null ]
    ] ],
    [ "enet_config_t", "group__lpc__enet.html#structenet__config__t", [
      [ "specialControl", "group__lpc__enet.html#af74925cfaccdc7fba60392d3fadb8aaa", null ],
      [ "multiqueueCfg", "group__lpc__enet.html#afcb7f11b0fa6a7e4162c9e45f1193a6c", null ],
      [ "miiMode", "group__lpc__enet.html#af5d9f50ec02037d29f6ed4202ffdbc1f", null ],
      [ "miiSpeed", "group__lpc__enet.html#a073bdafc878d858c56533323322be6a9", null ],
      [ "miiDuplex", "group__lpc__enet.html#a0704352d744c4da14bf1e836e95ff072", null ],
      [ "pauseDuration", "group__lpc__enet.html#a4ad647d398242d29ca34f03903e119a7", null ]
    ] ],
    [ "enet_tx_bd_ring_t", "group__lpc__enet.html#structenet__tx__bd__ring__t", [
      [ "txBdBase", "group__lpc__enet.html#a4441799607db26410d039a1dcac8961a", null ],
      [ "txGenIdx", "group__lpc__enet.html#a02d0c1d6dbec35379899b6d7fded3967", null ],
      [ "txConsumIdx", "group__lpc__enet.html#acb25ecf9088ef35f7806a0af21ad9893", null ],
      [ "txDescUsed", "group__lpc__enet.html#a190b8b21e481538bab2eb3800aaf84f0", null ],
      [ "txRingLen", "group__lpc__enet.html#ae5a88ae171688c9e8cc729e59b9424e7", null ]
    ] ],
    [ "enet_rx_bd_ring_t", "group__lpc__enet.html#structenet__rx__bd__ring__t", [
      [ "rxBdBase", "group__lpc__enet.html#a134988134218ce3e7575d6acbeae9c96", null ],
      [ "rxGenIdx", "group__lpc__enet.html#a3358045d4fa5d0656a5972dc6aea7b03", null ],
      [ "rxRingLen", "group__lpc__enet.html#a8cc38f123dc2aca3c0728d37e8c1c7f5", null ],
      [ "rxBuffSizeAlign", "group__lpc__enet.html#a63bdd0ba75b74fea1c360b87eb006d1d", null ]
    ] ],
    [ "enet_handle_t", "group__lpc__enet.html#struct__enet__handle", [
      [ "multiQueEnable", "group__lpc__enet.html#a4095070de9caa4b1175908753d3ec1c4", null ],
      [ "doubleBuffEnable", "group__lpc__enet.html#ad504f24402311f170f8a0c34ae668866", null ],
      [ "rxintEnable", "group__lpc__enet.html#af65f4fdf4111063b753328647f19d0ad", null ],
      [ "rxBdRing", "group__lpc__enet.html#a2ec7e58f48872dbf86f45d961ac04711", null ],
      [ "txBdRing", "group__lpc__enet.html#a564d5e6db8887c0660507b49619123c3", null ],
      [ "callback", "group__lpc__enet.html#ab6f1673b4b3b633bd4e6b0fa8732ea58", null ],
      [ "userData", "group__lpc__enet.html#a0fca53e60f7e5646f409633651d8e249", null ]
    ] ],
    [ "FSL_ENET_DRIVER_VERSION", "group__lpc__enet.html#ga869f211125798c5e1f17464dee22704e", null ],
    [ "ENET_RXDESCRIP_RD_BUFF1VALID_MASK", "group__lpc__enet.html#ga1ea6bb6e031d0b2421ab161e4b6a6b0e", null ],
    [ "ENET_RXDESCRIP_RD_BUFF2VALID_MASK", "group__lpc__enet.html#ga5128aebc859abc84737087e545f5108d", null ],
    [ "ENET_RXDESCRIP_RD_IOC_MASK", "group__lpc__enet.html#ga00bef5859f00fee663fde8d7736219f4", null ],
    [ "ENET_RXDESCRIP_RD_OWN_MASK", "group__lpc__enet.html#ga894c0bff0aa38ff22549cb6df51db353", null ],
    [ "ENET_RXDESCRIP_WR_ERR_MASK", "group__lpc__enet.html#gabc10ac0b86735627bae576af5dd94d7e", null ],
    [ "ENET_TXDESCRIP_RD_BL1_MASK", "group__lpc__enet.html#gaf92478ff739055167dd0403cf019fcb9", null ],
    [ "ENET_TXDESCRIP_WB_TTSS_MASK", "group__lpc__enet.html#ga4b38d700d2a85fde1a1681fc1bebf30e", null ],
    [ "ENET_FRAME_MAX_FRAMELEN", "group__lpc__enet.html#ga4fa46b5ee409f6d147980adc57493f6d", null ],
    [ "ENET_ADDR_ALIGNMENT", "group__lpc__enet.html#ga4a9bb13861a87d7cd78ab1e01fe7f807", null ],
    [ "ENET_BUFF_ALIGNMENT", "group__lpc__enet.html#ga0f83120d7461f8851bd187aa747693e4", null ],
    [ "ENET_RING_NUM_MAX", "group__lpc__enet.html#ga1c7f4f77e70346df3a28bc9cece517d4", null ],
    [ "ENET_MTL_RXFIFOSIZE", "group__lpc__enet.html#ga1f0f76ea4d7691cf15962fb3e2f29f7e", null ],
    [ "ENET_MTL_TXFIFOSIZE", "group__lpc__enet.html#gaa10654cd266ffde0d1799aa9aa8dbc84", null ],
    [ "ENET_MACINT_ENUM_OFFSET", "group__lpc__enet.html#ga3cbf0175c3e34f97e9ffaa85c3fea069", null ],
    [ "enet_callback_t", "group__lpc__enet.html#ga9a2cd914e4a6cf632f94621c2837fa98", null ],
    [ "_enet_status", "group__lpc__enet.html#ga2763713429a9379805f0e70ddd22df0c", [
      [ "kStatus_ENET_RxFrameError", "group__lpc__enet.html#gga2763713429a9379805f0e70ddd22df0caef1f945a6dc8fcf6267d57aac2a19f99", null ],
      [ "kStatus_ENET_RxFrameFail", "group__lpc__enet.html#gga2763713429a9379805f0e70ddd22df0ca97bf0aacb16c8874c7a0a016483cb2ec", null ],
      [ "kStatus_ENET_RxFrameEmpty", "group__lpc__enet.html#gga2763713429a9379805f0e70ddd22df0ca50e097caecebfb4afacf2c8a667a5409", null ],
      [ "kStatus_ENET_TxFrameBusy", "group__lpc__enet.html#gga2763713429a9379805f0e70ddd22df0cad15b9b2af39f28f90889bb19f568e844", null ],
      [ "kStatus_ENET_TxFrameFail", "group__lpc__enet.html#gga2763713429a9379805f0e70ddd22df0ca34b4c8ff24db933516a0cf13fc8174ad", null ],
      [ "kStatus_ENET_TxFrameOverLen", "group__lpc__enet.html#gga2763713429a9379805f0e70ddd22df0caf12461c772f3ff70fc5a8664bb49701e", null ]
    ] ],
    [ "enet_mii_mode_t", "group__lpc__enet.html#ga4ae0699c0a7f9706deffbaf201025669", [
      [ "kENET_MiiMode", "group__lpc__enet.html#gga4ae0699c0a7f9706deffbaf201025669a8625ad828cb3aae19fa0c2e6934e9368", null ],
      [ "kENET_RmiiMode", "group__lpc__enet.html#gga4ae0699c0a7f9706deffbaf201025669ae44236ebbdfcc0ae1e3520edd3d2d602", null ]
    ] ],
    [ "enet_mii_speed_t", "group__lpc__enet.html#ga8bbf729066c3400712a19ed1d9179e4c", [
      [ "kENET_MiiSpeed10M", "group__lpc__enet.html#gga8bbf729066c3400712a19ed1d9179e4ca6e8f095a5a1944d54425565b5beb835c", null ],
      [ "kENET_MiiSpeed100M", "group__lpc__enet.html#gga8bbf729066c3400712a19ed1d9179e4ca267390f53c987b908852257bf5407e8e", null ]
    ] ],
    [ "enet_mii_duplex_t", "group__lpc__enet.html#ga0784f279168ea4e3fc2fc07018dcb9bf", [
      [ "kENET_MiiHalfDuplex", "group__lpc__enet.html#gga0784f279168ea4e3fc2fc07018dcb9bfad3b58af3cb1b983f8e3cd45b585c91b9", null ],
      [ "kENET_MiiFullDuplex", "group__lpc__enet.html#gga0784f279168ea4e3fc2fc07018dcb9bfa0d2ad2c3708231614c716bc921503d6c", null ]
    ] ],
    [ "enet_mii_normal_opcode", "group__lpc__enet.html#ga39b76af2e9d33d5fbefe41854a01d9e5", [
      [ "kENET_MiiWriteFrame", "group__lpc__enet.html#gga39b76af2e9d33d5fbefe41854a01d9e5a655ca94d757517bb491287a925673476", null ],
      [ "kENET_MiiReadFrame", "group__lpc__enet.html#gga39b76af2e9d33d5fbefe41854a01d9e5a889519fb7ca76ef2598db81799677e46", null ]
    ] ],
    [ "enet_dma_burstlen", "group__lpc__enet.html#gad528020dfe62980955724d77798680d2", [
      [ "kENET_BurstLen1", "group__lpc__enet.html#ggad528020dfe62980955724d77798680d2a96cd5aa747a3a57371d9ed74cb9a1f06", null ],
      [ "kENET_BurstLen2", "group__lpc__enet.html#ggad528020dfe62980955724d77798680d2ae8da2a5daa96ea507805e070b80666e8", null ],
      [ "kENET_BurstLen4", "group__lpc__enet.html#ggad528020dfe62980955724d77798680d2a32d560f243d31e08a9d0ab7d64243967", null ],
      [ "kENET_BurstLen8", "group__lpc__enet.html#ggad528020dfe62980955724d77798680d2a72260c539aff5a7627bd1c42cbedd92b", null ],
      [ "kENET_BurstLen16", "group__lpc__enet.html#ggad528020dfe62980955724d77798680d2af244ab313f0364dba610c7c5c705b93a", null ],
      [ "kENET_BurstLen32", "group__lpc__enet.html#ggad528020dfe62980955724d77798680d2a230bad34d52836b4dab149d34bd840e0", null ],
      [ "kENET_BurstLen64", "group__lpc__enet.html#ggad528020dfe62980955724d77798680d2adcd9c6404bc804da3ecebc98b5f3a493", null ],
      [ "kENET_BurstLen128", "group__lpc__enet.html#ggad528020dfe62980955724d77798680d2a11fdf22d781186269bd6e7e27280aab3", null ],
      [ "kENET_BurstLen256", "group__lpc__enet.html#ggad528020dfe62980955724d77798680d2a2f54dfa6a5d6b79ef26d689464a691aa", null ]
    ] ],
    [ "enet_desc_flag", "group__lpc__enet.html#gab3290866c10bd6700765de2bd3bd3a52", [
      [ "kENET_MiddleFlag", "group__lpc__enet.html#ggab3290866c10bd6700765de2bd3bd3a52a623bd8f7a3ab8f2ef9f350c57d334849", null ],
      [ "kENET_FirstFlagOnly", "group__lpc__enet.html#ggab3290866c10bd6700765de2bd3bd3a52af9069e77d0443ff27198fa7db7a864be", null ],
      [ "kENET_LastFlagOnly", "group__lpc__enet.html#ggab3290866c10bd6700765de2bd3bd3a52a88046a3252126b965e2e3f3036329243", null ],
      [ "kENET_FirstLastFlag", "group__lpc__enet.html#ggab3290866c10bd6700765de2bd3bd3a52a725fc7fb74b364391d7cb4ead6e4500e", null ]
    ] ],
    [ "enet_systime_op", "group__lpc__enet.html#gaad326a47c4f3ddc23bd7f515c40249cc", [
      [ "kENET_SystimeAdd", "group__lpc__enet.html#ggaad326a47c4f3ddc23bd7f515c40249cca8d369da34e175d93a7ac2921582880ce", null ],
      [ "kENET_SystimeSubtract", "group__lpc__enet.html#ggaad326a47c4f3ddc23bd7f515c40249ccaae8e2cab6efa92f5d1136601548fc18d", null ]
    ] ],
    [ "enet_ts_rollover_type", "group__lpc__enet.html#gac78a6419d38c315e58ad2ac1057eacf2", [
      [ "kENET_BinaryRollover", "group__lpc__enet.html#ggac78a6419d38c315e58ad2ac1057eacf2ae0b6582a962fc755ee48fe7f4405b54c", null ],
      [ "kENET_DigitalRollover", "group__lpc__enet.html#ggac78a6419d38c315e58ad2ac1057eacf2ace5b8034ea3fbf806ba7f134f7335df1", null ]
    ] ],
    [ "enet_special_config_t", "group__lpc__enet.html#ga4dab6ac97d6bfddfec4ec8d2ffa003de", [
      [ "kENET_DescDoubleBuffer", "group__lpc__enet.html#gga4dab6ac97d6bfddfec4ec8d2ffa003deabdd0d1fcff6f690641784a93c93489d9", null ],
      [ "kENET_StoreAndForward", "group__lpc__enet.html#gga4dab6ac97d6bfddfec4ec8d2ffa003deae9d8ba2862bcea349033800b30a22500", null ],
      [ "kENET_PromiscuousEnable", "group__lpc__enet.html#gga4dab6ac97d6bfddfec4ec8d2ffa003deac520b8c9da899801e71870a3aec2cad3", null ],
      [ "kENET_FlowControlEnable", "group__lpc__enet.html#gga4dab6ac97d6bfddfec4ec8d2ffa003dea1cf1e03a128def3a0a436662ae50f77b", null ],
      [ "kENET_BroadCastRxDisable", "group__lpc__enet.html#gga4dab6ac97d6bfddfec4ec8d2ffa003dea3cb5f46c40130ff2411f8201dc29d23d", null ],
      [ "kENET_MulticastAllEnable", "group__lpc__enet.html#gga4dab6ac97d6bfddfec4ec8d2ffa003dea50ed874d96171204fd7650c572ea72a9", null ],
      [ "kENET_8023AS2KPacket", "group__lpc__enet.html#gga4dab6ac97d6bfddfec4ec8d2ffa003dea5a57fd15eef3f7181825c6bd68af790e", null ]
    ] ],
    [ "enet_dma_interrupt_enable_t", "group__lpc__enet.html#ga85c3c8a9d8c2ec00920108633644cd46", [
      [ "kENET_DmaTx", "group__lpc__enet.html#gga85c3c8a9d8c2ec00920108633644cd46aa0170f2d49497830180289d47cce0a46", null ],
      [ "kENET_DmaTxStop", "group__lpc__enet.html#gga85c3c8a9d8c2ec00920108633644cd46aa4750546b5f28be529a82bf306a2f145", null ],
      [ "kENET_DmaTxBuffUnavail", "group__lpc__enet.html#gga85c3c8a9d8c2ec00920108633644cd46a281d6ba15e66644dd444ddb52466263c", null ],
      [ "kENET_DmaRx", "group__lpc__enet.html#gga85c3c8a9d8c2ec00920108633644cd46a925ab4ba4c92c71236ab4606d074dc99", null ],
      [ "kENET_DmaRxBuffUnavail", "group__lpc__enet.html#gga85c3c8a9d8c2ec00920108633644cd46aa8695b8f25f5e61f042d29cd1fd50773", null ],
      [ "kENET_DmaRxStop", "group__lpc__enet.html#gga85c3c8a9d8c2ec00920108633644cd46a64eefbba6229fa5144f90d675e272203", null ],
      [ "kENET_DmaRxWatchdogTimeout", "group__lpc__enet.html#gga85c3c8a9d8c2ec00920108633644cd46ab09ad89eb883cbe966f40c2b7229d6cb", null ],
      [ "kENET_DmaEarlyTx", "group__lpc__enet.html#gga85c3c8a9d8c2ec00920108633644cd46a2f8eadb69a6c19f9ed2ba266daa2a99c", null ],
      [ "kENET_DmaEarlyRx", "group__lpc__enet.html#gga85c3c8a9d8c2ec00920108633644cd46a95ef82164ba763996b050c0f419aff92", null ],
      [ "kENET_DmaBusErr", "group__lpc__enet.html#gga85c3c8a9d8c2ec00920108633644cd46afa9cb9e3c21b91256b2bc4ff65a123b1", null ]
    ] ],
    [ "enet_mac_interrupt_enable_t", "group__lpc__enet.html#gab7882f7b274124d8b95289bc15bf8d59", null ],
    [ "enet_event_t", "group__lpc__enet.html#gab6a6012153064f5996a44ecb79559fbe", [
      [ "kENET_RxIntEvent", "group__lpc__enet.html#ggab6a6012153064f5996a44ecb79559fbea8a29f697f047aacc21a4acd5ac0b94ea", null ],
      [ "kENET_TxIntEvent", "group__lpc__enet.html#ggab6a6012153064f5996a44ecb79559fbeac54e1e301d12a7d0b02e40e099e6e1c2", null ],
      [ "kENET_WakeUpIntEvent", "group__lpc__enet.html#ggab6a6012153064f5996a44ecb79559fbea58d45dcfe99e3db2581683831c14420d", null ],
      [ "kENET_TimeStampIntEvent", "group__lpc__enet.html#ggab6a6012153064f5996a44ecb79559fbea2a3dcc67c11b1cadfad78165c0f75f89", null ]
    ] ],
    [ "enet_dma_tx_sche", "group__lpc__enet.html#ga2753bc64cb7e84ad2d4aa3f48d1cb362", [
      [ "kENET_FixPri", "group__lpc__enet.html#gga2753bc64cb7e84ad2d4aa3f48d1cb362aeb94a36e85d534d387d98f9d507dad38", null ],
      [ "kENET_WeightStrPri", "group__lpc__enet.html#gga2753bc64cb7e84ad2d4aa3f48d1cb362abaea864cd595d4b68ea7ddd4dd1bcb79", null ],
      [ "kENET_WeightRoundRobin", "group__lpc__enet.html#gga2753bc64cb7e84ad2d4aa3f48d1cb362ac88e921101d88e58133b8c2b6a534a31", null ]
    ] ],
    [ "enet_mtl_multiqueue_txsche", "group__lpc__enet.html#ga1c0c0c5e195fe155ba692af1afa2fd1d", [
      [ "kENET_txWeightRR", "group__lpc__enet.html#gga1c0c0c5e195fe155ba692af1afa2fd1dafa6c6e079d0a775db2d4196fce985fe2", null ],
      [ "kENET_txStrPrio", "group__lpc__enet.html#gga1c0c0c5e195fe155ba692af1afa2fd1dacc79a8902085c91e66047772931527f3", null ]
    ] ],
    [ "enet_mtl_multiqueue_rxsche", "group__lpc__enet.html#gacf3bb6eb6a5a66cf094913af5c3369fc", [
      [ "kENET_rxStrPrio", "group__lpc__enet.html#ggacf3bb6eb6a5a66cf094913af5c3369fca3db9d79af3a1b8ef38ee2eb6c98ea810", null ],
      [ "kENET_rxWeightStrPrio", "group__lpc__enet.html#ggacf3bb6eb6a5a66cf094913af5c3369fcafedca4dd7c8cef45fcf1eac6ec784e12", null ]
    ] ],
    [ "enet_mtl_rxqueuemap", "group__lpc__enet.html#gaf4bbe8b38e5ed7cb083e666d96d2200e", [
      [ "kENET_StaticDirctMap", "group__lpc__enet.html#ggaf4bbe8b38e5ed7cb083e666d96d2200ea9822e0718741a44a17a690b20c9872ab", null ],
      [ "kENET_DynamicMap", "group__lpc__enet.html#ggaf4bbe8b38e5ed7cb083e666d96d2200ea3b49128c202a7a27634088aa4feb018f", null ]
    ] ],
    [ "enet_ptp_event_type_t", "group__lpc__enet.html#gad81d00443312853a5c0d47555e7cdd51", [
      [ "kENET_PtpEventMsgType", "group__lpc__enet.html#ggad81d00443312853a5c0d47555e7cdd51a7c6a58d3732ed04ae74feb6542b4d55f", null ],
      [ "kENET_PtpSrcPortIdLen", "group__lpc__enet.html#ggad81d00443312853a5c0d47555e7cdd51abb1c450a7ae22c6e9a10bf1ea0fde539", null ],
      [ "kENET_PtpEventPort", "group__lpc__enet.html#ggad81d00443312853a5c0d47555e7cdd51ac10a2ea90a3156b111fe49f8abfd3ddb", null ],
      [ "kENET_PtpGnrlPort", "group__lpc__enet.html#ggad81d00443312853a5c0d47555e7cdd51a1626b69803cd82170f72476e05106345", null ]
    ] ],
    [ "ENET_GetDefaultConfig", "group__lpc__enet.html#gaf0992a0c9c3a27b2a40226ac38a26d1e", null ],
    [ "ENET_Init", "group__lpc__enet.html#ga2673c7697d18b090f1f8102fa6769908", null ],
    [ "ENET_Deinit", "group__lpc__enet.html#ga72f7e3493a2f4134324e9e72492bdbbc", null ],
    [ "ENET_DescriptorInit", "group__lpc__enet.html#ga778b50d6345fb6f06f6dcb4edd09c831", null ],
    [ "ENET_StartRxTx", "group__lpc__enet.html#gafd02ac0a534900de54887cef6b3442d2", null ],
    [ "ENET_SetMII", "group__lpc__enet.html#ga34b5bac04b5423f78fff25dea87a47e7", null ],
    [ "ENET_SetSMI", "group__lpc__enet.html#gaecbfcdaef940eedce9f45f7f443d90be", null ],
    [ "ENET_IsSMIBusy", "group__lpc__enet.html#ga8b858eb8a45a1fccab444dfbc8263c24", null ],
    [ "ENET_ReadSMIData", "group__lpc__enet.html#ga22ec536c31d024bce85bac71e16646f5", null ],
    [ "ENET_StartSMIRead", "group__lpc__enet.html#ga96f9560063d42b0f5ffca2eb6c9e9abf", null ],
    [ "ENET_StartSMIWrite", "group__lpc__enet.html#gacac17f8946afbbe56355fa90cc005f6b", null ],
    [ "ENET_SetMacAddr", "group__lpc__enet.html#ga7c30b3e913924a70f81d458de50f403c", null ],
    [ "ENET_GetMacAddr", "group__lpc__enet.html#ga89e5a62af8d1ebf7359faa1fc13b56bc", null ],
    [ "ENET_EnterPowerDown", "group__lpc__enet.html#ga193d295c941e323af516cd4af0210dc3", null ],
    [ "ENET_ExitPowerDown", "group__lpc__enet.html#gafc71470563a250fc0e9558d554a78519", null ],
    [ "ENET_EnableInterrupts", "group__lpc__enet.html#ga7245fddbc8b02f1670f45691cc84d0ef", null ],
    [ "ENET_DisableInterrupts", "group__lpc__enet.html#ga6471771bfa420ed928db65e3c8e88b4b", null ],
    [ "ENET_GetDmaInterruptStatus", "group__lpc__enet.html#gaed64b6763239317592d99eab5fe42742", null ],
    [ "ENET_ClearDmaInterruptStatus", "group__lpc__enet.html#ga201aa691ec311b8719f96a6f1bc318b5", null ],
    [ "ENET_GetMacInterruptStatus", "group__lpc__enet.html#ga4b6d3c60d02535c152b3f5d9dbf984d7", null ],
    [ "ENET_ClearMacInterruptStatus", "group__lpc__enet.html#gabfcad9fd0a667ae6df436ea0db6469e0", null ],
    [ "ENET_IsTxDescriptorDmaOwn", "group__lpc__enet.html#ga11616f998c765c8bf6406f3519de2b8d", null ],
    [ "ENET_SetupTxDescriptor", "group__lpc__enet.html#gada2ccb4d0a18d154e61f4a492065ab9f", null ],
    [ "ENET_UpdateTxDescriptorTail", "group__lpc__enet.html#ga3962af24a80981cfd63bba73c778d134", null ],
    [ "ENET_UpdateRxDescriptorTail", "group__lpc__enet.html#ga1e692bd43c2c9c235c81b4e8d60fd17b", null ],
    [ "ENET_GetRxDescriptor", "group__lpc__enet.html#ga4c8e742ca37d8cae0e58473c1db541a7", null ],
    [ "ENET_UpdateRxDescriptor", "group__lpc__enet.html#gaa850c8defc0dcc2544f3e1249477d55b", null ],
    [ "ENET_CreateHandler", "group__lpc__enet.html#gab7059136554f0858bce26913bdb0f018", null ],
    [ "ENET_GetRxFrameSize", "group__lpc__enet.html#gaa9cbedbc591c46cc4c539110c03e5882", null ],
    [ "ENET_ReadFrame", "group__lpc__enet.html#ga3e2b53f5183f26145b97cca782689023", null ],
    [ "ENET_SendFrame", "group__lpc__enet.html#gaab45575aff382eece62289f530b4bd9d", null ],
    [ "ENET_ReclaimTxDescriptor", "group__lpc__enet.html#gaeaccd9b061b331523c439405a3865036", null ],
    [ "ENET_PMTIRQHandler", "group__lpc__enet.html#gaae3f9406784a89c63061d3b4ef2e3b14", null ],
    [ "ENET_IRQHandler", "group__lpc__enet.html#ga7ab049214ddc382229412def84349a34", null ]
];