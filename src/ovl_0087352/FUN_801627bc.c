/* FUN_801627bc
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x801627bc  body 0x801627bc..0x80162a47  size 652 B
 * body sha256 49c7012457fd279f8ce4c40285b203eece211324ba5cba29b473a5c2081e3c73
 * provider record sha256 2f5ebb08fa41bafa60b04abc0e9c45262a775571273464a8ebf6f466d6b3da69
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801627bc(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  ushort uVar4;
  char cVar5;
  uint uVar2;
  int iVar3;
  int iVar6;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    uVar2 = func_0x80033604();
    uVar1 = func_0x80033604();
    if ((uVar1 & 1) != 0) {
      func_0x80077d18(1,param_1);
    }
    uVar1 = func_0x80033604();
    if ((uVar1 & 7) == 0) {
      FUN_801661d8(param_1,1);
    }
    *(uint *)(param_1 + 0x1e8) = (uVar2 & 7) * 0x10000 + 0x7000700;
    *(undefined1 *)(param_1 + 0x2b9) = 0;
    uVar4 = func_0x80033604();
    *(ushort *)(param_1 + 0x1e0) = (uVar4 & 0x1f) + 100;
    *(undefined2 *)(param_1 + 0x1e2) = 0xfff6;
    *(char *)(param_1 + 0x2b5) = '\t' - (char)(uVar2 & 7);
    *(undefined1 *)(param_1 + 0x2b4) = 1;
    *(undefined1 *)(param_1 + 6) = 5;
    *(ushort *)(param_1 + 0x2c6) = *(ushort *)(param_1 + 0x2c6) | 1;
    goto switchD_80162800_caseD_5;
  case 1:
    *(undefined2 *)(param_1 + 0x1e2) = 0xffb0;
    *(undefined1 *)(param_1 + 0x2b5) = 6;
    *(undefined1 *)(param_1 + 0x2b4) = 2;
    break;
  case 2:
    uVar2 = func_0x80033604();
    if ((uVar2 & 1) != 0) {
      func_0x80077d18(1,param_1);
    }
    *(undefined2 *)(param_1 + 0x1e2) = 0xffc4;
    *(undefined1 *)(param_1 + 0x2b5) = 4;
    *(undefined1 *)(param_1 + 0x2b4) = 3;
    break;
  case 3:
    *(undefined2 *)(param_1 + 0x1e2) = 0xff9c;
    *(undefined1 *)(param_1 + 0x2b5) = 9;
    *(undefined1 *)(param_1 + 0x2b4) = 4;
    break;
  case 4:
    uVar2 = func_0x80033604();
    if ((uVar2 & 7) == 0) {
      FUN_801661d8(param_1,1);
    }
    *(undefined2 *)(param_1 + 0x1e2) = 0xffb0;
    *(undefined1 *)(param_1 + 0x2b5) = 0xff;
    break;
  case 5:
    goto switchD_80162800_caseD_5;
  default:
    goto switchD_80162800_default;
  }
  *(undefined1 *)(param_1 + 6) = 5;
switchD_80162800_caseD_5:
  cVar5 = *(char *)(param_1 + 0x2b5) + -1;
  *(char *)(param_1 + 0x2b5) = cVar5;
  if (cVar5 == '\0') {
    *(undefined1 *)(param_1 + 6) = *(undefined1 *)(param_1 + 0x2b4);
  }
  uVar2 = func_0x80033604();
  if ((uVar2 & 1) == 0) {
    iVar3 = _DAT_800e1158;
    iVar6 = _DAT_800e1160;
  }
  else {
    iVar3 = _DAT_800e1158 - *(int *)(param_1 + 0x28);
    iVar6 = _DAT_800e1160 - *(int *)(param_1 + 0x30);
  }
  func_0x80032dbc(param_1,iVar3,iVar6,0x20);
  func_0x80032bd8(param_1,0,0);
  if (*(short *)(param_1 + 0x1e0) < 300) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 1;
  }
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar3 != 0) {
    FUN_80165c68(param_1,4);
  }
switchD_80162800_default:
  return;
}
