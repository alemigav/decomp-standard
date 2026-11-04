/* FUN_80163b60
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80163b60  body 0x80163b60..0x80163d8f  size 560 B
 * body sha256 23e3dbccf9ce7060aa175eb8efaa6a11def014e9d7915f88dd15e1e2f39251df
 * provider record sha256 bb1b9edc59af44f201b732fd66c2dc03c738188322586f104d782e4c98b7131f
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163b60(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar4;
  short sVar2;
  byte bVar5;
  int iVar1;
  ushort uVar3;
  undefined4 uVar6;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    cVar4 = func_0x80033144(param_1,0x800e1130);
    FUN_80165c58(0x800e1130,2,cVar4 != '\0');
    func_0x80052bd0(4,0);
    func_0x80052c6c(10,0x96,0);
    func_0x80077d18(4,param_1);
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000700;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(undefined1 *)(param_1 + 0x2ba) = 0;
    *(undefined2 *)(param_1 + 0x2c0) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  case 1:
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
  case 2:
    sVar2 = *(short *)(param_1 + 0x2c0) + 0x14;
    *(short *)(param_1 + 0x2c0) = sVar2;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)sVar2;
    iVar1 = *(short *)(param_1 + 0x25e) + -0xfa;
    if (iVar1 < *(int *)(param_1 + 0x2c)) {
      func_0x80077d18(5,param_1);
      *(int *)(param_1 + 0x2c) = iVar1;
      *(undefined4 *)(param_1 + 0x1e8) = 0xb000700;
      bVar5 = func_0x80033604();
      *(byte *)(param_1 + 0x2b5) = bVar5 & 0xf;
      *(undefined1 *)(param_1 + 6) = 3;
    }
    break;
  case 3:
    cVar4 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar4;
    if (cVar4 == -1) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)(param_1 + 0x1e9) = *(char *)(param_1 + 0x1e9) + -1;
    break;
  case 4:
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      iVar1 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),
                              (int)*(short *)(param_1 + 0x262),0x400);
      if (iVar1 == 0) {
        uVar6 = 9;
      }
      else {
        uVar3 = func_0x80033604(param_1);
        *(ushort *)(param_1 + 500) = uVar3 & 0xf;
        uVar6 = 0;
      }
      FUN_80165c68(param_1,uVar6);
    }
  }
  return;
}
