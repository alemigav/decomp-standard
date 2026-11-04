/* FUN_80165328
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165328  body 0x80165328..0x801654f7  size 464 B
 * body sha256 b63d61c1ee5e16d0cea77e6ca1dadcb28227a0aa123d49410dad12bdd146d84a
 * provider record sha256 f8d78d00bc87143ca59d3474bd9b59b0fcd171d41632b0ffe657bd6fed4779f1
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165328(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  cVar1 = *(char *)(param_1 + 5);
  if (*(char *)(param_1 + 6) == '\0') {
    if (cVar1 == '\t') {
      FUN_80166270(param_1,0,4);
    }
    FUN_80166270(param_1,2,1);
    if ((*(byte *)(param_1 + 0x26e) < 3) || (cVar1 != '\t')) {
      if ((cVar1 == '\t') || ((cVar1 == '\x11' || (cVar1 == '\x13')))) {
        uVar5 = 0;
        iVar3 = 0;
        do {
          uVar5 = uVar5 + 1;
          iVar4 = *(int *)(param_1 + 0x234) + iVar3;
          iVar3 = iVar3 + 0x178;
          *(undefined4 *)(iVar4 + 0x60) = 0x502040;
        } while (uVar5 < 0xd);
        FUN_80166270(param_1,0,0xd);
      }
      iVar3 = *(int *)(param_1 + 0x234);
      if ((DAT_800e9012 & 8) != 0) {
        *(uint *)(iVar3 + 0x2f0) = *(uint *)(iVar3 + 0x2f0) | 0x44a;
        uVar2 = *(undefined2 *)(param_1 + 0x66);
        *(undefined2 *)(iVar3 + 0x424) = 0xffe2;
        *(undefined2 *)(iVar3 + 0x422) = 0xffec;
        *(undefined2 *)(iVar3 + 0x426) = 2;
        *(undefined2 *)(iVar3 + 0x42c) = 0xfffb;
        *(undefined2 *)(iVar3 + 0x428) = 0;
        *(undefined4 *)(iVar3 + 0x350) = 0x101010;
        *(undefined2 *)(iVar3 + 0x414) = 0xc00;
        *(undefined2 *)(iVar3 + 0x416) = 0xc00;
        *(undefined2 *)(iVar3 + 0x418) = 0xc00;
        *(undefined2 *)(iVar3 + 0x420) = uVar2;
      }
      uVar5 = 0xe;
      do {
        FUN_801663a4(param_1,1,uVar5);
        FUN_801663a4(param_1,0xc,uVar5);
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0x12);
    }
    FUN_801651c0(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_80166830)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
  }
  return;
}
