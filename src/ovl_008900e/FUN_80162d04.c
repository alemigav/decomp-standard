/* FUN_80162d04
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80162d04  body 0x80162d04..0x80162e0f  size 268 B
 * body sha256 1ae991559c3a5dd7ede044f759adf30f1d27858f49f47ffeb9985e9e2cbd8ce8
 * provider record sha256 22d4bf93709d51487e22ecc9b774bcd940d76be91f94178036a2d7773ca14a98
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162d04(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x234);
  if (*(char *)(param_1 + 0x2cf) == '\0') {
    DAT_80168d50 = &DAT_80168b10;
    *(code **)(param_1 + 0x2d8) = FUN_80162d04;
    *(char *)(param_1 + 0x2cf) = *(char *)(param_1 + 0x2cf) + '\x01';
  }
  else {
    do {
      if ((*(ushort *)(DAT_80168d50 + 10) & 2) == 0) {
        uVar2 = *(ushort *)(DAT_80168d50 + 8);
        uVar3 = func_0x80033604();
        func_0x80037780((uVar3 & 0xff) * 2 + 0x1000 | 0x6000000,0,iVar4 + (uint)uVar2 * 0x178 + 0x38
                        ,DAT_80168d50);
      }
      puVar1 = (ushort *)(DAT_80168d50 + 10);
      DAT_80168d50 = DAT_80168d50 + 0xc;
    } while ((*puVar1 & 1) != 0);
    if (*(char *)(param_1 + 0x2cf) == '\x10') {
      *(undefined4 *)(param_1 + 0x2d8) = 0;
    }
    *(char *)(param_1 + 0x2cf) = *(char *)(param_1 + 0x2cf) + '\x01';
  }
  return;
}
