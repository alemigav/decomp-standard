/* FUN_8002cfdc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002cfdc  body 0x8002cfdc..0x8002d163  size 392 B
 * body sha256 5663d73026ff8644ea5e4a030bf68323458609e372f90a991baab0a74d253486
 * provider record sha256 3a56a790aaec1cc64ca66652b8f8edbf13345c8d5ade069ca4059abce88a688f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002cfdc(int *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = param_1[0x58];
  iVar2 = *(int *)(param_1[0x5d] + 0x58);
  *(undefined4 *)(*param_1 + 0x14) = 0x6b;
  *(int *)(*param_1 + 0x18) = iVar4;
  *(int *)(*param_1 + 0x1c) = iVar2;
  (**(code **)(*param_1 + 4))(param_1,0xffffffff);
  bVar1 = iVar4 < 0xc0;
  while( true ) {
    while( true ) {
      uVar3 = 2;
      if ((((!bVar1) && (uVar3 = 3, iVar4 - 0xd0U < 8)) && (iVar4 != (iVar2 + 1U & 7) + 0xd0)) &&
         (((iVar4 != (iVar2 + 2U & 7) + 0xd0 && (uVar3 = 2, iVar4 != (iVar2 - 1U & 7) + 0xd0)) &&
          (uVar3 = 1, iVar4 == (iVar2 - 2U & 7) + 0xd0)))) {
        uVar3 = 2;
      }
      *(undefined4 *)(*param_1 + 0x14) = 0x59;
      *(int *)(*param_1 + 0x18) = iVar4;
      *(uint *)(*param_1 + 0x1c) = uVar3;
      (**(code **)(*param_1 + 4))(param_1,4);
      if (uVar3 == 2) break;
      if (uVar3 < 3) {
        bVar1 = iVar4 < 0xc0;
        if (uVar3 == 1) {
          param_1[0x58] = 0;
          return 1;
        }
      }
      else {
        bVar1 = iVar4 < 0xc0;
        if (uVar3 == 3) {
          return 1;
        }
      }
    }
    iVar4 = FUN_8002c9c0(param_1);
    if (iVar4 == 0) break;
    iVar4 = param_1[0x58];
    bVar1 = iVar4 < 0xc0;
  }
  return 0;
}
