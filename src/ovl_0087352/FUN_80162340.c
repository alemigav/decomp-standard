/* FUN_80162340
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80162340  body 0x80162340..0x8016271f  size 992 B
 * body sha256 e5a8ed869d3433c7fd8b7ff8e3c8522712d7b4e8c14f25159735bae10d2db526
 * provider record sha256 822b23524ca2d4e9dc1eb16c736e32093fb7249f63fda731bf8f42216cbcd59f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162340(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar4;
  char cVar5;
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar6;
  undefined4 uVar7;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    uVar2 = func_0x80033604();
    uVar2 = uVar2 & 0xff;
    uVar1 = (uint)((ulonglong)uVar2 * 0x51eb851f >> 0x20);
    *(undefined1 *)(param_1 + 6) = 7;
    goto LAB_8016262c;
  case 1:
    uVar1 = func_0x80033604();
    *(undefined1 *)(param_1 + 0x2b5) = 5;
    *(undefined1 *)(param_1 + 6) = 10;
    *(uint *)(param_1 + 0x1e8) = ((uVar1 & 0xff) % 5) * 0x10000 + 0x700;
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
    *(undefined1 *)(param_1 + 6) = 8;
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
    *(undefined1 *)(param_1 + 6) = 9;
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
    *(undefined1 *)(param_1 + 6) = 0xb;
    break;
  case 5:
    uVar1 = func_0x80033604();
    uVar1 = uVar1 & 0xff;
    *(undefined1 *)(param_1 + 6) = 8;
    *(uint *)(param_1 + 0x1e8) =
         (uVar1 + (uVar1 / 7 + (uVar1 - uVar1 / 7 >> 1) >> 2) * -7 & 0xff) * 0x10000 + 0x2000700;
    break;
  case 6:
    *(undefined4 *)(param_1 + 0x1e8) = 0xa000700;
    bVar4 = func_0x80033604();
    *(undefined1 *)(param_1 + 6) = 0xd;
    *(undefined2 *)(param_1 + 0x2c0) = *(undefined2 *)(param_1 + 0x2a);
    *(undefined2 *)(param_1 + 0x2c2) = *(undefined2 *)(param_1 + 0x32);
    *(byte *)(param_1 + 0x2b5) = bVar4 % 5 + 0xf;
    break;
  case 7:
    if (*(char *)(param_1 + 0x2b5) == '\0') {
      uVar1 = func_0x80033604();
      uVar1 = uVar1 & 0xff;
      uVar1 = uVar1 + (uVar1 / 7 + (uVar1 - uVar1 / 7 >> 1) >> 2) * -7;
      uVar6 = (undefined1)uVar1;
      *(undefined1 *)(param_1 + 0x2b4) = uVar6;
      if ((uVar1 & 0xff) == 6) {
        uVar1 = func_0x80033604();
        if ((uVar1 & 0xf) == 0) {
          *(undefined1 *)(param_1 + 6) = uVar6;
        }
        else {
          *(undefined1 *)(param_1 + 6) = 0;
        }
      }
      else {
        *(undefined1 *)(param_1 + 6) = uVar6;
      }
    }
    goto LAB_80162664;
  case 8:
switchD_80162380_caseD_8:
    goto LAB_801625d8;
  case 9:
    uVar7 = 0x10200;
    goto LAB_801625e0;
  case 10:
    cVar5 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar5;
    if ((cVar5 == -1) && ((*(ushort *)(param_1 + 0x2c6) & 0x20) == 0)) {
      uVar1 = func_0x80033604(param_1,param_2);
      if ((uVar1 & 1) != 0) {
        func_0x80077d18(6,param_1);
      }
      goto switchD_80162380_caseD_8;
    }
LAB_801625d8:
    uVar7 = 0x200;
LAB_801625e0:
    iVar3 = func_0x80089d54(param_1,param_2,param_3,uVar7);
    if (iVar3 != 0) {
      *(undefined1 *)(param_1 + 6) = 0;
    }
    break;
  case 0xb:
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar3 == 0) {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 0xc;
    uVar2 = func_0x80033604();
    uVar2 = uVar2 & 0xff;
    uVar1 = (uint)((ulonglong)uVar2 * 0x51eb851f >> 0x20);
LAB_8016262c:
    *(char *)(param_1 + 0x2b5) = (char)uVar2 + (char)(uVar1 >> 5) * -100;
    break;
  case 0xc:
    if (*(char *)(param_1 + 0x2b5) == '\0') {
      *(undefined1 *)(param_1 + 6) = 3;
    }
LAB_80162664:
    *(char *)(param_1 + 0x2b5) = *(char *)(param_1 + 0x2b5) + -1;
    break;
  case 0xd:
    func_0x80089d54(param_1,param_2,param_3,0x10200);
    FUN_80165bc4(param_1);
    if (*(char *)(param_1 + 0x1e9) == *(char *)(param_1 + 0x2b5)) {
      *(undefined1 *)(param_1 + 6) = 0xe;
      *(uint *)(param_1 + 0x1e8) = (0x27 - (uint)*(byte *)(param_1 + 0x2b5)) * 0x10000 + 0xa000700;
    }
    break;
  case 0xe:
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar3 == 0) {
      FUN_80165bc4(param_1);
    }
    else {
      *(undefined1 *)(param_1 + 6) = 0;
      *(int *)(param_1 + 0x28) = (int)*(short *)(param_1 + 0x2c0);
      *(int *)(param_1 + 0x30) = (int)*(short *)(param_1 + 0x2c2);
    }
  }
  return;
}
