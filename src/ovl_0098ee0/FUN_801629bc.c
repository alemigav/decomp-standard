/* FUN_801629bc
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x801629bc  body 0x801629bc..0x80162ac7  size 268 B
 * body sha256 bc865452eb2edee7c8470a3721a1480ae1824cd2e4d8013df18c9279ea32f8a3
 * provider record sha256 c33344838cbe7d5ae80f6443fecff99b74b9693631c84b3e3260d682d13dc810
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801629bc(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x234);
  if (*(char *)(param_1 + 0x2c4) == '\0') {
    DAT_80166908 = &DAT_80166704;
    *(code **)(param_1 + 700) = FUN_801629bc;
    *(char *)(param_1 + 0x2c4) = *(char *)(param_1 + 0x2c4) + '\x01';
  }
  else {
    do {
      if ((*(ushort *)(DAT_80166908 + 10) & 2) == 0) {
        uVar2 = *(ushort *)(DAT_80166908 + 8);
        uVar3 = func_0x80033604();
        func_0x80037780((uVar3 & 0xff) * 2 + 0x1000 | 0x6000000,0,iVar4 + (uint)uVar2 * 0x178 + 0x38
                        ,DAT_80166908);
      }
      puVar1 = (ushort *)(DAT_80166908 + 10);
      DAT_80166908 = DAT_80166908 + 0xc;
    } while ((*puVar1 & 1) != 0);
    if (*(char *)(param_1 + 0x2c4) == '\x18') {
      *(undefined4 *)(param_1 + 700) = 0;
    }
    *(char *)(param_1 + 0x2c4) = *(char *)(param_1 + 0x2c4) + '\x01';
  }
  return;
}
