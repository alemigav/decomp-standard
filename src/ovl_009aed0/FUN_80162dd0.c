/* FUN_80162dd0
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162dd0  body 0x80162dd0..0x80162edb  size 268 B
 * body sha256 ca654974d0a1d5e95b45645ade8926edb5c345f55e3443a42f175f73082a9dad
 * provider record sha256 dc5e916052afb35c05231e9fcd2cfdd45ccb35b766ce77aaf7eb9e999fc30c2d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162dd0(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x234);
  if (*(char *)(param_1 + 0x2c4) == '\0') {
    DAT_8016665c = &DAT_8016640c;
    *(code **)(param_1 + 700) = FUN_80162dd0;
    *(char *)(param_1 + 0x2c4) = *(char *)(param_1 + 0x2c4) + '\x01';
  }
  else {
    do {
      if ((*(ushort *)(DAT_8016665c + 10) & 2) == 0) {
        uVar2 = *(ushort *)(DAT_8016665c + 8);
        uVar3 = func_0x80033604();
        func_0x80037780((uVar3 & 0xff) * 2 + 0x1400 | 0x6000000,0,iVar4 + (uint)uVar2 * 0x178 + 0x38
                        ,DAT_8016665c);
      }
      puVar1 = (ushort *)(DAT_8016665c + 10);
      DAT_8016665c = DAT_8016665c + 0xc;
    } while ((*puVar1 & 1) != 0);
    if (*(char *)(param_1 + 0x2c4) == '\x15') {
      *(undefined4 *)(param_1 + 700) = 0;
    }
    *(char *)(param_1 + 0x2c4) = *(char *)(param_1 + 0x2c4) + '\x01';
  }
  return;
}
