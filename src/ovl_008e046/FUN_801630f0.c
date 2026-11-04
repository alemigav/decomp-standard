/* FUN_801630f0
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x801630f0  body 0x801630f0..0x801632bf  size 464 B
 * body sha256 cf503d0c8ab615b5d55a36581dc16b845ed8a2311f14d01def575b7e26e7e147
 * provider record sha256 5db137e48b35aa89e7eac6474170407ebcfbe75ae6e5ad947a122a0d91ae8ee1
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801630f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar3;
  char cVar4;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 0x2ce) = 4;
  iVar1 = FUN_80162768();
  *(int *)(param_1 + 0x2c4) = iVar1;
  if (iVar1 != 0) {
    if (*(char *)(param_1 + 0x2b5) == '\x01') {
      *(undefined4 *)(param_1 + 4) = 0x10e0000;
      return;
    }
    if (*(char *)(param_1 + 0x2b5) == '\x02') {
      *(undefined4 *)(param_1 + 4) = 0x10f0000;
      return;
    }
    return;
  }
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
  case 3:
    *(undefined4 *)(param_1 + 0x1e8) = 0x3002f00;
    *(undefined1 *)(param_1 + 0x2cc) = 0;
    bVar3 = *(char *)(param_1 + 7) + 1;
    *(byte *)(param_1 + 7) = bVar3;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
    if (bVar3 < 2) {
      *(undefined1 *)(param_1 + 6) = 1;
      goto switchD_80163178_caseD_1;
    }
    *(undefined2 *)(param_1 + 6) = 0x400;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
  case 4:
    FUN_80162f58(param_1,0xc,0);
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar1 = func_0x8008a994(param_1,param_2,param_3,0x80);
    if ((iVar1 != 0) && (uVar2 = func_0x80033604(param_1), (uVar2 & 3) == 0)) {
      *(undefined2 *)(param_1 + 6) = 0;
    }
    func_0x80032c6c(param_1,0,0);
    break;
  case 1:
switchD_80163178_caseD_1:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar1 = func_0x8008a994(param_1,param_2,param_3,0x55);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 6) = 3;
    }
    func_0x80032b5c(param_1,0);
    break;
  case 2:
    cVar4 = func_0x8008a994(param_1,param_2,param_3,0x10400);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
  }
  return;
}
