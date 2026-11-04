/* FUN_80163be8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80163be8  body 0x80163be8..0x80163d6b  size 388 B
 * body sha256 b69559bf1442a4c3cc407838d683534c954bbe2f7fd31132213e7dbecba4ce95
 * provider record sha256 5120d6bb5df57a1ba5a8ae5eab4a198279a50d18d110ffa498311af526a11a40
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163be8(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  short sVar2;
  undefined1 uVar3;
  byte bVar4;
  short sVar5;
  
  bVar4 = *(byte *)(param_1 + 6);
  if (bVar4 == 1) {
LAB_80163c90:
    *(undefined1 *)(param_1 + 6) = 2;
    bVar4 = func_0x80033604();
    *(byte *)(param_1 + 0x206) = (bVar4 & 0xf) + 0xf;
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
LAB_80163cb4:
    FUN_80166c70(param_1,(int)*(short *)(param_1 + 0x1f6));
    uVar3 = 6;
    if ((*(ushort *)(param_1 + 0x2c2) & 0xfff) != (*(ushort *)(param_1 + 500) & 0xfff)) {
      cVar1 = *(char *)(param_1 + 0x206);
      *(char *)(param_1 + 0x206) = cVar1 + -1;
      if (cVar1 == '\x01') {
        *(undefined1 *)(param_1 + 6) = 3;
        bVar4 = func_0x80033604();
        *(byte *)(param_1 + 0x206) = (bVar4 & 0xf) + 1;
        *(undefined4 *)(param_1 + 0x1e8) = 0x300;
      }
      goto LAB_80163d40;
    }
  }
  else {
    if (1 < bVar4) {
      if (bVar4 != 2) {
        if ((bVar4 == 3) &&
           (cVar1 = *(char *)(param_1 + 0x206), *(char *)(param_1 + 0x206) = cVar1 + -1,
           cVar1 == '\x01')) {
          *(undefined1 *)(param_1 + 6) = 1;
        }
        goto LAB_80163d40;
      }
      goto LAB_80163cb4;
    }
    if (bVar4 != 0) goto LAB_80163d40;
    *(undefined1 *)(param_1 + 6) = 1;
    sVar2 = FUN_80166f84(param_1,0x20);
    *(short *)(param_1 + 0x1f6) = sVar2;
    if (sVar2 != 0) {
      sVar5 = -0x400;
      if (0 < sVar2) {
        sVar5 = 0x400;
      }
      *(short *)(param_1 + 500) = sVar5;
      if (*(char *)(param_1 + 0x2cc) == '\0') {
        *(short *)(param_1 + 500) = -sVar5;
      }
      goto LAB_80163c90;
    }
    uVar3 = 7;
  }
  *(undefined1 *)(param_1 + 5) = uVar3;
  *(undefined2 *)(param_1 + 6) = 0;
LAB_80163d40:
  func_0x80089d54(param_1,param_2,param_3,0x400);
  FUN_80167938(param_1);
  return;
}
