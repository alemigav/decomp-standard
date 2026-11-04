/* FUN_801661d8
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x801661d8  body 0x801661d8..0x80166293  size 188 B
 * body sha256 cc7098acb24af4a8f3714f0cdd18e5900cfdbff762b29245c86daf0fef1c5bbf
 * provider record sha256 836dd720396928df38d80c2576af089c7e6130185fc2ff17ea12b81f5cfa7f7c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801661d8(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  short local_20;
  short local_1e;
  short local_1c;
  
  iVar3 = param_2 + -1;
  if (param_2 != 0) {
    do {
      iVar3 = iVar3 + -1;
      iVar1 = func_0x80033604();
      local_20 = *(short *)(param_1 + 0x2a) + (short)((iVar1 << 0x18) >> 0x16);
      iVar1 = func_0x80033604();
      local_1e = *(short *)(param_1 + 0x2e) + (short)((iVar1 << 0x18) >> 0x16);
      iVar1 = func_0x80033604();
      local_1c = *(short *)(param_1 + 0x32) + (short)((iVar1 << 0x18) >> 0x16);
      uVar2 = func_0x80033604();
      func_0x80037780(0xc000800,(uVar2 & 0xff) << 4,0x800e9028,&local_20);
    } while (iVar3 != -1);
  }
  return;
}
