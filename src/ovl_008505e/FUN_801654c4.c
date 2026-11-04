/* FUN_801654c4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801654c4  body 0x801654c4..0x8016555b  size 152 B
 * body sha256 6309491fde8907af1f5a91425d9920b43c74f5d335827eac47fe69810a267c17
 * provider record sha256 ec57cf5caa7ce18942ec1c42718c3444a304f423bc384f23a2085b529cc6c29e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801654c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  ushort uVar2;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    uVar1 = func_0x80033604();
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 500) + (uVar1 & 0xff) * 2 + -0x100);
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + ((uVar2 & 0xff) - 0x80);
  }
  FUN_80164f14(param_1,param_2,param_3);
  return;
}
