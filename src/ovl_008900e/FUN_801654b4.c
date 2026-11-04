/* FUN_801654b4
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801654b4  body 0x801654b4..0x801658cb  size 1048 B
 * body sha256 43aece86ca8eb05d5313502b4d8ceb17c364c52ac217dfe63840a08f13f93920
 * provider record sha256 7df0daa8d586af5b5c1905cb210b14b601deee3a19c6df5cc588470503141d5a
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801654b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar2;
  int iVar1;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = 400;
  uVar4 = 0;
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined1 *)(param_1 + 0x2dd) = 0;
    *(undefined2 *)(param_1 + 0x2de) = 0;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 0x2e0) = *(undefined2 *)(param_1 + 0x2e);
    if ((*(ushort *)(param_1 + 0x2c8) & 2) != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x6000300;
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
      goto switchD_80165510_caseD_1;
    }
    *(undefined1 *)(param_1 + 6) = 2;
  case 2:
    *(undefined1 *)(param_1 + 0x2ce) = 3;
    *(undefined1 *)(param_1 + 0x2dd) = 0xf6;
    *(undefined2 *)(param_1 + 0x2de) = 0;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffd;
    func_0x80077d18(8,param_1);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  case 3:
    cVar2 = func_0x80036be4(param_1,0x1f,0,0,uVar3,uVar4);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    func_0x80032dbc(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                    *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),6);
    break;
  case 1:
switchD_80165510_caseD_1:
    cVar2 = func_0x8008a994(param_1,param_2,param_3,0x10400);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    break;
  case 4:
    *(undefined2 *)(param_1 + 0x1e0) = 0x226;
    *(undefined2 *)(param_1 + 0x1e2) = 0xff0b;
    *(undefined1 *)(param_1 + 0x2dd) = 0xf8;
    *(undefined2 *)(param_1 + 0x2de) = 0x23;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -0x72f;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 0x200;
  case 5:
    cVar2 = func_0x80036be4(param_1,0x20,0,0,400,0);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    func_0x80032dbc(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                    *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x20);
    if ((((*(char *)(*(int *)(param_1 + 0x2c4) + 0x26f) == '\0') &&
         (*(byte *)(param_1 + 0x1e9) - 0xb < 4)) &&
        (iVar1 = FUN_80168654(param_1), iVar1 + 199U < 0x38f)) &&
       ((*(uint *)(param_1 + 0x28c) < 0x898 && (*(short *)(param_1 + 500) == 0)))) {
      *(code **)(param_1 + 0x2d8) = FUN_801658cc;
      *(undefined1 *)(param_1 + 0x2cf) = 0;
      *(undefined2 *)(param_1 + 500) = 1;
      *(int *)(*(int *)(param_1 + 0x2c4) + 0x250) = param_1;
      func_0x80052bd0(10,0);
      func_0x80052d10(0x16,0xff,0x32,3);
      func_0x80052d10(0xc,0x37,0x28,0x16);
      uVar3 = 0x50;
      if (0x6e < *(short *)(*(int *)(param_1 + 0x2c4) + 0x1f2)) {
        uVar3 = 100;
      }
      func_0x80059e00(uVar3,0);
      func_0x80077d18(10,param_1);
      iVar1 = *(int *)(param_1 + 0x2c4);
      if (*(short *)(iVar1 + 0x1f2) < 0) {
        *(undefined2 *)(iVar1 + 0x1f2) = 0xffff;
        _DAT_800e1134 = 0x3000000;
        _DAT_800e10ec = _DAT_800e10ec | 0x4000100;
        _DAT_800e1324 = func_0x80033144(param_1,0x800e1130);
        _DAT_800e1324 = _DAT_800e1324 & 0xff;
      }
      else {
        if (*(short *)(iVar1 + 0x1f2) < 0x28) {
          *(undefined2 *)(iVar1 + 0x1f2) = 0x28;
        }
        *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 4) = 0x2020000;
        cVar2 = func_0x80033144(param_1,0x800e1130);
        *(char *)(*(int *)(param_1 + 0x2c4) + 5) = *(char *)(*(int *)(param_1 + 0x2c4) + 5) + cVar2;
      }
    }
    break;
  case 6:
    *(undefined4 *)(param_1 + 0x1e8) = 0x201c0000;
    if (*(int *)(param_1 + 0x2c) <= *(short *)(param_1 + 0x2e0) + -0x60f) break;
    *(undefined1 *)(param_1 + 0x2dd) = 0xc4;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x2de) = 0;
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x2e0);
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfdff;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  case 7:
    iVar1 = func_0x80036be4(param_1,0x21,0,0,400,0);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x10f0000;
    }
    break;
  default:
    break;
  }
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
  func_0x80032b5c(param_1,0);
  *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + (short)*(char *)(param_1 + 0x2dd);
  *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + *(short *)(param_1 + 0x2de);
  if (*(short *)(param_1 + 0x1e0) < 0) {
    *(undefined1 *)(param_1 + 0x2dd) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
  }
  return;
}
