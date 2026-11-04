/* FUN_801649ac
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801649ac  body 0x801649ac..0x80164e4f  size 1188 B
 * body sha256 b6ec109969b433287c10870dcdecfa1dc08606277f122f6df452c1504b3cd2c2
 * provider record sha256 29fae27c5ab2a3d27a37c7e29e6d03fcfbc1090f09c53192f80e8ed7146d6ca6
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801649ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  ushort uVar3;
  uint uVar2;
  int iVar4;
  short local_30;
  short local_2e;
  short local_2c;
  
  *(undefined1 *)(param_1 + 0x2b5) = 0;
  *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x80;
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0xe000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    local_30 = 400;
    local_2e = 100;
    local_2c = 0;
    func_0x80037780(0x13d0,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x4a0,
                    &local_30);
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
    *(undefined2 *)(param_1 + 0x1f6) = *(undefined2 *)(param_1 + 0x1f2);
    func_0x80077d18(0xc,param_1);
    _DAT_800e110c = _DAT_800e110c & 0xfffffff7;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    *(undefined2 *)(param_1 + 0x1f2) = 9000;
    return;
  }
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (((cVar1 == '\x1e') || (cVar1 == '#')) || (cVar1 == '2')) {
    local_30 = 300;
    local_2e = 0;
    local_2c = 0;
    func_0x80037780(0x13d0,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x4a0,
                    &local_30);
  }
  if (*(byte *)(param_1 + 0x1e9) - 6 < 0x13) {
    iVar4 = *(int *)(param_1 + 0x234);
    local_30 = 400;
    uVar3 = func_0x80033604();
    local_2e = (uVar3 & 0xff) * -2 + -0x2c;
    uVar3 = func_0x80033604();
    local_2c = 0x80 - (uVar3 & 0xff);
    uVar2 = func_0x80033604();
    func_0x80037780(0x17b8,(uVar2 & 0xff) << 4,iVar4 + 0x328,&local_30);
    uVar3 = func_0x80033604();
    local_2e = (uVar3 & 0xff) * -2 + -0x2c;
    uVar3 = func_0x80033604();
    local_2c = 0x80 - (uVar3 & 0xff);
    uVar2 = func_0x80033604();
    func_0x80037780(0x117b8,(uVar2 & 0xff) << 4,iVar4 + 0x328,&local_30);
    if (*(char *)(param_1 + 0x1e9) == '\x0f') {
      *(uint *)(iVar4 + 0x2f0) = *(uint *)(iVar4 + 0x2f0) | 0x80;
      *(undefined4 *)(iVar4 + 0x420) = 0x101030;
      *(undefined4 *)(iVar4 + 0x424) = 0x101020;
    }
  }
  if (*(ushort *)(param_1 + 0x136) < 0x44c) {
    *(ushort *)(param_1 + 0x136) = *(ushort *)(param_1 + 0x136) + 5;
    *(short *)(param_1 + 0x138) = *(short *)(param_1 + 0x138) + 5;
    *(short *)(param_1 + 0x12e) = *(short *)(param_1 + 0x12e) + 5;
    *(short *)(param_1 + 300) = *(short *)(param_1 + 300) + 5;
  }
  iVar4 = *(int *)(param_1 + 0x234);
  *(ushort *)(*(int *)(iVar4 + 0x410) + 0x10) =
       *(short *)(*(int *)(iVar4 + 0x410) + 0x10) + (*(byte *)(param_1 + 0x1e9) & 1) * -0x80;
  if (*(byte *)(param_1 + 0x1e9) - 0x3d < 0x1f) {
    *(short *)(*(int *)(iVar4 + 0x410) + 0x10) = *(short *)(*(int *)(iVar4 + 0x410) + 0x10) + 0x40;
    *(short *)(*(int *)(iVar4 + 0x410) + 0xc) = *(short *)(*(int *)(iVar4 + 0x410) + 0xc) + 0x80;
  }
  func_0x80066288(param_1,iVar4 + 0x2f0);
  *(ushort *)(*(int *)(iVar4 + 0x410) + 0x10) =
       *(short *)(*(int *)(iVar4 + 0x410) + 0x10) + (*(byte *)(param_1 + 0x1e9) & 1) * 0x80;
  if (0x14 < *(byte *)(param_1 + 0x1e9)) {
    iVar4 = *(int *)(param_1 + 0x234);
    *(short *)(*(int *)(iVar4 + 0x298) + 0xc) = *(short *)(*(int *)(iVar4 + 0x298) + 0xc) + 0x40;
    if (0x1000 < *(short *)(*(int *)(iVar4 + 0x298) + 0xc)) {
      *(undefined2 *)(*(int *)(iVar4 + 0x298) + 0xc) = 0x1000;
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x20;
    }
    func_0x80066288(param_1,iVar4 + 0x178);
  }
  if ((*(byte *)(param_1 + 0x1e9) - 0x15 < 0x29) && ((*(byte *)(param_1 + 0x1e9) & 3) == 0)) {
    iVar4 = *(int *)(param_1 + 0x234);
    uVar3 = func_0x80033604();
    local_30 = 0x16c - (uVar3 & 0x7f);
    local_2e = 200;
    uVar3 = func_0x80033604();
    local_2c = 0x16c - (uVar3 & 0x7f);
    iVar4 = iVar4 + 0x328;
    func_0x80037780(0x13d0,(int)*(short *)(param_1 + 0x66),iVar4,&local_30);
    uVar3 = func_0x80033604();
    local_2c = -0xec - (uVar3 & 0x7f);
    func_0x80037780(0x13d0,(int)*(short *)(param_1 + 0x66),iVar4,&local_30);
  }
  if (*(char *)(param_1 + 0x1e9) == '(') {
    iVar4 = *(int *)(param_1 + 0x234);
    *(uint *)(iVar4 + 0x178) = *(uint *)(iVar4 + 0x178) | 0x80;
    *(undefined4 *)(iVar4 + 0x2a8) = 0x101040;
    *(undefined4 *)(iVar4 + 0x2ac) = 0x101020;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar4 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar4 == 0) {
    func_0x80032b5c(param_1,0);
    *(undefined2 *)(param_1 + 0x1f2) = 9000;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 10;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xff7f | 0x100;
    *(short *)(param_1 + 0x1f2) = *(short *)(param_1 + 0x1f6);
    if (100 < *(short *)(param_1 + 0x1f6)) {
      *(undefined2 *)(param_1 + 0x1f2) = 100;
    }
  }
  return;
}
