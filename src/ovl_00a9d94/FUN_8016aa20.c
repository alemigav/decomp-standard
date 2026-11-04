/* FUN_8016aa20
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016aa20  body 0x8016aa20..0x8016ab83  size 356 B
 * body sha256 c81aa4faacde712b808787a4451b8f843185dd05e2f70a184f9651ee0a48be26
 * provider record sha256 5d381288b39558817d3c84e5414e6a7c20d3079dccfa04be4db69584ee3244f3
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016aa20(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_38 [20];
  int local_24;
  int local_1c;
  
  iVar2 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  func_0x800424ec(param_1 + 0x14,iVar2 + 8,auStack_38);
  func_0x800424ec(auStack_38,iVar2 + 0xd40,auStack_38);
  func_0x800424ec(auStack_38,iVar2 + 0xeb8,auStack_38);
  if (param_3 == 0) {
    iVar3 = iVar2 + 0x1be8;
    func_0x800424ec(auStack_38,iVar2 + 0x1610,auStack_38);
  }
  else {
    iVar3 = iVar2 + 0x1490;
  }
  func_0x800424ec(auStack_38,iVar3 + -0x460,auStack_38);
  func_0x800424ec(auStack_38,iVar3 + -0x2e8,auStack_38);
  func_0x800424ec(auStack_38,iVar3 + -0x170,auStack_38);
  func_0x800424ec(auStack_38,iVar3 + 8,auStack_38);
  if (param_2 == 0) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (local_24 - *(int *)(iVar3 + 0x4c));
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - (local_1c - *(int *)(iVar3 + 0x54));
  }
  else {
    local_24 = local_24 - *(int *)(iVar3 + 0x4c);
    local_1c = local_1c - *(int *)(iVar3 + 0x54);
    uVar1 = func_0x80040bb4(local_24 * local_24 + local_1c * local_1c);
    *(undefined2 *)(param_1 + 0x1e0) = uVar1;
  }
  return;
}
