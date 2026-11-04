/* FUN_80040584
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040584  body 0x80040584..0x80040793  size 528 B
 * body sha256 28bced713e98ca49652be2bbef8ff6bab0321a1b6d27dfa004aa2d0f2d3860bd
 * provider record sha256 7ffc529d5042167ce3a234455d521f8f31054e0beb32cf4b192eb37ace66b90a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040584(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  switch(DAT_800ebb94[2]) {
  case 0:
    uVar3 = FUN_80033604();
    uVar3 = uVar3 & 0xff;
    uVar4 = (uint)((ulonglong)uVar3 * 0x88888889 >> 0x20);
    uVar1 = *(ushort *)(DAT_800ebb94 + 0x3a);
    uVar5 = *(undefined4 *)(DAT_800ebb94 + 0x6c);
    break;
  case 1:
  case 3:
    uVar4 = FUN_80033604();
    FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0x2060000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar4 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    uVar3 = FUN_80033604();
    uVar3 = uVar3 & 0xff;
    uVar4 = (uint)((ulonglong)uVar3 * 0x88888889 >> 0x20);
    uVar1 = *(ushort *)(DAT_800ebb94 + 0x3a);
    uVar5 = *(undefined4 *)(DAT_800ebb94 + 0x6c);
    break;
  case 6:
    uVar4 = FUN_80033604();
    FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0x2060000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar4 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    puVar2 = DAT_800ebb94;
    DAT_800ebb94[1] = 0;
    *puVar2 = 0;
    *(undefined2 *)(puVar2 + 0x18) = 0;
  default:
    goto LAB_8004076c;
  }
  FUN_80038a20(uVar1 | 0x2060000,
               (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) +
                     (uVar3 + (uVar4 >> 4) * -0x1e & 0xff) * 400) * 0x10000) >> 0x10,uVar5,
               DAT_800ebb94 + 0x2c);
LAB_8004076c:
  DAT_800ebb94[2] = DAT_800ebb94[2] + '\x01';
  return;
}
