/* FUN_80033680
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033680  body 0x80033680..0x800337c3  size 324 B
 * body sha256 b20bacf9dea245e200647f0e122b6944b919c323e418bad8929a4909a360d5bb
 * provider record sha256 9153801ec3d82681de52954adabb6db6ce56bd03213905df756315735da225e4
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80033680(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 auStack_38 [20];
  int local_24;
  int local_1c;
  
  iVar2 = *(int *)(param_1 + 0x234);
  FUN_80040e58(param_1 + 100,param_1 + 0x14);
  FUN_800424ec(param_1 + 0x14,iVar2 + 8,auStack_38);
  FUN_800424ec(auStack_38,iVar2 + 0x180,auStack_38);
  iVar2 = iVar2 + param_3 * 0x468 + 0x5e0;
  FUN_800424ec(auStack_38,iVar2 + -0x2e8,auStack_38);
  FUN_800424ec(auStack_38,iVar2 + -0x170,auStack_38);
  FUN_800424ec(auStack_38,iVar2 + 8,auStack_38);
  if (param_2 == 0) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (local_24 - *(int *)(iVar2 + 0x4c));
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - (local_1c - *(int *)(iVar2 + 0x54));
  }
  else {
    local_24 = local_24 - *(int *)(iVar2 + 0x4c);
    local_1c = local_1c - *(int *)(iVar2 + 0x54);
    uVar1 = FUN_80040bb4(local_24 * local_24 + local_1c * local_1c);
    *(undefined2 *)(param_1 + 0x1e0) = uVar1;
  }
  return;
}
