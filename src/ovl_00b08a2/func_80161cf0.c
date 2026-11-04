/* func_80161cf0
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161fe7  size 760 B
 * body sha256 41aee22543d52b72d2193aa391fee45c8ebdb33679e57cc7ed8b7e31e2a9e377
 * provider record sha256 d934bdade50dc783a8f0fb67eb0f8983e722f5d07f32326e629cbefcde256aec
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  byte bVar1;
  undefined2 uVar2;
  short sVar3;
  short sVar5;
  uint uVar4;
  uint *puVar6;
  uint *in_a0;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_18;
  undefined4 local_14;
  
  if ((_DAT_800e1110 & 0x20000000) != 0) {
    return;
  }
  if (*(short *)((int)in_a0 + 0x1aa) == 8) {
    FUN_801668ec();
    *in_a0 = *in_a0 & 0xfffffffe;
    return;
  }
  if ((*(byte *)((int)in_a0 + 0x26f) & 0x7f) != 0) {
    *(byte *)((int)in_a0 + 0x26f) = *(byte *)((int)in_a0 + 0x26f) - 1;
  }
  if (*(char *)(in_a0 + 1) != '\0') {
    bVar1 = *(byte *)((int)in_a0 + 0x2b5);
    if (bVar1 != 1) {
      if (bVar1 < 2) {
        if (bVar1 != 0) goto LAB_80161ed8;
        iVar7 = *(int *)(_DAT_800e13f0 + 0x234);
        local_18 = *(undefined4 *)(&DAT_801670f0 + (uint)*(byte *)(in_a0 + 0xad) * 8);
        local_14 = *(undefined4 *)(&DAT_801670f4 + (uint)*(byte *)(in_a0 + 0xad) * 8);
      }
      else {
        if (bVar1 != 2) goto LAB_80161ed8;
        iVar7 = *(int *)(_DAT_800e13f0 + 0x234);
        iVar9 = *(int *)(&DAT_801670f4 + (uint)*(byte *)(in_a0 + 0xad) * 8);
        iVar8 = *(int *)(&DAT_801670f0 + (uint)*(byte *)(in_a0 + 0xad) * 8) << 0x10;
        local_14 = CONCAT22((short)((iVar9 >> 0x10) - (iVar9 >> 0x1f) >> 1),(short)iVar9);
        sVar3 = (short)((iVar8 >> 0x10) - (iVar8 >> 0x1f) >> 1);
        sVar5 = sVar3 + -0x514;
        local_18._0_2_ =
             (short)((uint)*(int *)(&DAT_801670f0 + (uint)*(byte *)(in_a0 + 0xad) * 8) >> 0x10);
        if (*(byte *)(in_a0 + 0xad) - 1 < 2) {
          sVar5 = sVar3 + -0x5dc;
        }
        local_18 = CONCAT22(local_18._0_2_,sVar5);
      }
      func_0x8004276c(iVar7 + 0x328,&local_18,&local_18);
      in_a0[10] = *(int *)(iVar7 + 0x33c) + (int)local_18._0_2_;
      in_a0[0xb] = *(int *)(iVar7 + 0x340) + (int)local_18._2_2_;
      in_a0[0xc] = *(int *)(iVar7 + 0x344) + (int)local_14._0_2_;
    }
  }
LAB_80161ed8:
  (*(code *)(&PTR_FUN_80167110)[*(byte *)(in_a0 + 1)])();
  FUN_80166e00();
  if ((in_a0[0xaf] & 0x10000) == 0) {
    uVar4 = in_a0[0x8d];
    uVar2 = *(undefined2 *)(uVar4 + 0x124);
    *(undefined2 *)(uVar4 + 0x29c) = uVar2;
    *(undefined2 *)(uVar4 + 0x414) = uVar2;
    *(undefined2 *)(uVar4 + 0x58c) = uVar2;
  }
  func_0x80033648();
  FUN_801667a4();
  puVar6 = *(uint **)((*(byte *)(in_a0 + 0xad) + 7) * 4 + -0x7ff1ec18);
  *puVar6 = *puVar6 | 1;
  puVar6 = *(uint **)((*(byte *)(in_a0 + 0xad) + 7) * 4 + -0x7ff1ec18);
  *puVar6 = *puVar6 & 0xffefffff;
  if ((*in_a0 & 0x100000) != 0) {
    puVar6 = *(uint **)((*(byte *)(in_a0 + 0xad) + 7) * 4 + -0x7ff1ec18);
    *puVar6 = *puVar6 | 0x100000;
  }
  return;
}
