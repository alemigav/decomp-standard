/* FUN_80165940
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80165940  body 0x80165940..0x80165e17  size 1240 B
 * body sha256 bf2dcc59d1ba3de03147df0a41d056f27f48a31e9463ec813754d91326a9bbd9
 * provider record sha256 b6930f65c3050dcb3981f293f4dd0469c3dbaad8d1a627a51938c07442551867
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165940(int param_1,int param_2)

{
  short sVar3;
  ushort uVar4;
  uint uVar1;
  uint uVar2;
  int iVar5;
  short local_18;
  short local_16;
  short local_14;
  
  switch(*(undefined1 *)(param_1 + 0x2b5)) {
  case 0:
    *(undefined1 *)(param_1 + 0x2b5) = 1;
    *(undefined2 *)(param_1 + 0x2b8) = 0;
    *(undefined2 *)(param_1 + 0x2ba) = 0;
    *(undefined1 *)(param_1 + 0x2b7) = 0;
  case 1:
    sVar3 = *(short *)(*(int *)(param_2 + 0x120) + 0x18);
    if (sVar3 != 0) {
      *(short *)(*(int *)(param_2 + 0x120) + 0x18) = sVar3 >> 1;
    }
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) - *(short *)(param_1 + 0x2b8);
    if (*(short *)(*(int *)(param_2 + 0x120) + 0xc) < -0xfd0) {
      *(undefined1 *)(param_1 + 0x2b5) = 2;
    }
    *(short *)(*(int *)(param_2 + 0x120) + 0x18) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x18) + (*(short *)(param_1 + 0x2b8) >> 1);
    *(short *)(param_1 + 0x2b8) = *(short *)(param_1 + 0x2b8) + 0x20;
    break;
  case 2:
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) + *(short *)(param_1 + 0x2b8);
    if (0 < *(short *)(*(int *)(param_2 + 0x120) + 0xc)) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0xc) = 0;
    }
    *(short *)(*(int *)(param_2 + 0x120) + 0x18) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x18) + *(short *)(param_1 + 0x2b8);
    if (0x15c4 < *(short *)(*(int *)(param_2 + 0x120) + 0x18)) {
      *(undefined1 *)(param_1 + 0x2b5) = 3;
      *(undefined2 *)(param_1 + 0x2ba) = 0xf;
      func_0x80077d18(6,param_1);
    }
    iVar5 = *(int *)(param_1 + 0x28) + ((int)((uint)*(ushort *)(param_1 + 0x2b8) << 0x10) >> 0x13);
    *(int *)(param_1 + 0x28) = iVar5;
    if (12000 < iVar5) {
      *(int *)(param_1 + 0x28) = iVar5 - ((int)((uint)*(ushort *)(param_1 + 0x2b8) << 0x10) >> 0x13)
      ;
    }
    if (10 < (int)((uint)*(ushort *)(param_1 + 0x2b8) << 0x10) >> 0x13) {
      *(undefined1 *)(param_1 + 0x2c1) = 4;
    }
    sVar3 = *(short *)(param_1 + 0x150) + 500;
    *(short *)(param_1 + 0x150) = sVar3;
    if (0xe74 < sVar3) {
      *(undefined2 *)(param_1 + 0x150) = 0xe74;
    }
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 900;
    iVar5 = func_0x80033024(param_1 + 0x140,&DAT_800e1158,0x5dc);
    if ((iVar5 != 0) &&
       ((DAT_800e139f == 0 ||
        ((((*(char *)(param_1 + 0x2b7) == '\0' && (-1 < _DAT_800e1322)) && (DAT_800e1134 == '\x05'))
         && (DAT_800e1135 < 2)))))) {
      func_0x80059e00(0x28,1);
      _DAT_800e1134 = 0x2020000;
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1380 = param_1;
      *(undefined1 *)(param_1 + 0x2b7) = 10;
      func_0x80077d18(0xe,param_1);
      func_0x80052bd0(8,0);
      func_0x80052c6c(10,0xfa,4);
    }
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + -900;
    *(short *)(param_1 + 0x2b8) = *(short *)(param_1 + 0x2b8) + 0x100;
    break;
  case 3:
    sVar3 = *(short *)(param_1 + 0x2ba) + -1;
    *(short *)(param_1 + 0x2ba) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 0x2b5) = 4;
    }
    *(ushort *)(*(int *)(param_2 + 0x120) + 0x18) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x18) + 0x40 +
         (*(ushort *)(param_1 + 0x2ba) & 1) * -0x100;
    break;
  case 4:
    *(short *)(*(int *)(param_2 + 0x120) + 0x18) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x18) + -0x40;
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 900;
    iVar5 = func_0x80033024(param_1 + 0x140,&DAT_800e1158,3000);
    if (iVar5 != 0) {
      *(short *)(*(int *)(param_2 + 0x120) + 0x18) =
           *(short *)(*(int *)(param_2 + 0x120) + 0x18) + -0x20;
    }
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + -900;
    if (*(short *)(*(int *)(param_2 + 0x120) + 0x18) < 0) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x18) = 0;
      *(undefined1 *)(param_1 + 0x2b4) = 0;
      *(undefined1 *)(param_1 + 0x2b5) = 0;
      *(undefined1 *)(param_1 + 0x2c5) = 5;
    }
    sVar3 = *(short *)(param_1 + 0x150) + -0xf;
    *(short *)(param_1 + 0x150) = sVar3;
    if (sVar3 < 0x898) {
      *(undefined2 *)(param_1 + 0x150) = 0x898;
    }
  }
  if (*(char *)(param_1 + 0x2b7) != '\0') {
    iVar5 = *(int *)(param_1 + 0x234);
    *(char *)(param_1 + 0x2b7) = *(char *)(param_1 + 0x2b7) + -1;
    local_18 = 0x4b0;
    uVar4 = func_0x80033604();
    local_16 = (uVar4 & 0xff) * 2 + 0x38;
    uVar4 = func_0x80033604();
    local_14 = (uVar4 & 0xff) + 0x80;
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    iVar5 = iVar5 + 0x618;
    func_0x80037780((uVar1 & 1) << 0x10 | (uVar2 & 0xff) * 4 + 0x2770,
                    (int)*(short *)(param_1 + 0x66),iVar5,&local_18);
    local_18 = 0x578;
    uVar4 = func_0x80033604();
    local_16 = (uVar4 & 0xff) * 2 + 0x38;
    uVar4 = func_0x80033604();
    local_14 = (uVar4 & 0xff) + 0x80;
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780((uVar1 & 1) << 0x10 | (uVar2 & 0xff) * 4 + 0x2770,
                    (int)*(short *)(param_1 + 0x66),iVar5,&local_18);
    iVar5 = _DAT_800e1364;
    uVar4 = func_0x80033604();
    local_18 = (uVar4 & 0xff) * -2 + 0x100;
    local_16 = 0;
    uVar4 = func_0x80033604();
    local_14 = (uVar4 & 0xff) * -2 + 0x100;
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780((uVar1 & 1) << 0x10 | (uVar2 & 0xff) * 4 + 0x17d0,0,iVar5 + 0x38,&local_18);
  }
  return;
}
