/* FUN_8007040c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007040c  body 0x8007040c..0x80070473  size 104 B
 * body sha256 572b212c6767d6b506c8ec25934bd8a5dcd9baaf1a84d135f88054b7ce9d31af
 * provider record sha256 1a66c515942688cef4a35fc5769516222904a52d19cb1158b717c2c8e171d7b1
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8007040c(int param_1)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x1c) + 2);
  sVar1 = *(short *)(*(int *)(param_1 + 0x1c) + 4);
  uVar3 = FUN_800704e0(*(undefined4 *)(param_1 + 0x154),uVar2 & 0xff);
  FUN_8006e838(uVar2 >> 8,uVar3,(int)sVar1);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 6;
  return 1;
}
