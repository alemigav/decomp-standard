/* FUN_801642b0
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801642b0  body 0x801642b0..0x80164443  size 404 B
 * body sha256 9fac81be8fef7fd48079da34853c7e4378e5fbb884645e8e08c0b30e44e96a16
 * provider record sha256 e0aef5cf444123e2c4a88f7672f387174eb5c2e4a4903233bd32961a06d009a1
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801642b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar3;
  int iVar2;
  undefined1 uVar4;
  undefined4 uVar5;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 == 1) {
LAB_80164340:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
    if (iVar2 == 0) goto LAB_80164424;
    uVar5 = 0x5000300;
    uVar4 = 2;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) goto LAB_80164424;
      *(undefined1 *)(param_1 + 6) = 1;
      uVar3 = func_0x80033604();
      *(ushort *)(param_1 + 500) = (uVar3 & 0xf) + 0x1e;
      *(undefined2 *)(param_1 + 0x1e0) = 300;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      *(undefined4 *)(param_1 + 0x1e8) = 0x4000300;
      goto LAB_80164340;
    }
    if (bVar1 != 2) {
      if ((bVar1 == 3) && (iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400), iVar2 != 0)) {
        *(undefined1 *)(param_1 + 5) = 4;
        *(undefined2 *)(param_1 + 6) = 0;
        *(undefined1 *)(param_1 + 0x2cd) = 0;
      }
      goto LAB_80164424;
    }
    FUN_80166cbc(param_1,0,0,0);
    func_0x80089d54(param_1,param_2,param_3,0x400);
    iVar2 = FUN_80166d58(param_1,(int)*(short *)(param_1 + 0x2c2));
    if (((iVar2 != 0) || (*(char *)(param_1 + 0xd) != -1)) ||
       ((*(uint *)(param_1 + 0x1ac) & 1) != 0)) {
      *(undefined1 *)(param_1 + 6) = 3;
      *(undefined4 *)(param_1 + 0x1e8) = 0x7000300;
    }
    iVar2 = FUN_8016741c(param_1,2000,0x10cc);
    if (iVar2 == 0) goto LAB_80164424;
    uVar5 = 0x7000300;
    uVar4 = 3;
  }
  *(undefined1 *)(param_1 + 6) = uVar4;
  *(undefined4 *)(param_1 + 0x1e8) = uVar5;
LAB_80164424:
  FUN_80167938(param_1);
  return;
}
