/* FUN_80162140
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162140  body 0x80162140..0x801621e7  size 168 B
 * body sha256 18863cf694a7fa9e62f97660cc68b9ccda823d3def8963eef13cc647acde49e6
 * provider record sha256 3da4e2db63aae4840f9b9f802f5b4d33f4b0dbbcb82f04a57543bb3190adfa06
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162140(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  uVar5 = 0;
  puVar4 = &DAT_801662e0;
  do {
    uVar1 = *puVar4;
    iVar3 = *(int *)(param_1 + 0x234);
    if (puVar4[9] != 0) {
      local_1c = 0;
      local_1e = 0;
      local_20 = 0;
      uVar2 = func_0x80033604();
      func_0x80037780(0x40e2000,(uVar2 & 0xff) << 4,iVar3 + (uint)uVar1 * 0x178 + 0x38,&local_20);
    }
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 10;
  } while (uVar5 < 0xf);
  return;
}
