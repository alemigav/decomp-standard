/* FUN_80166888
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80166888  body 0x80166888..0x80166d23  size 1180 B
 * body sha256 367b3a9a7f6206aa7687b4912e949e4d9a2a330be89116e9d0326e265da16ce0
 * provider record sha256 dfd9f259357d6c50d9b6ee032ec67eb9c9c62b19a677b450da7318fa1a93c1c1
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166888(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  short local_28;
  short local_26;
  short local_24;
  
  if (*(char *)((int)param_1 + 6) == '\0') {
    param_1[0x7a] = 0x1b000700;
    *(undefined1 *)((int)param_1 + 6) = 1;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x800);
    _DAT_800e1380 = param_1;
    func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
    _DAT_800e1134 = 0x5000000;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    iVar1 = 0x46;
    if (0xaa < _DAT_800e1322) {
      iVar1 = _DAT_800e1322 + -100;
    }
    iVar1 = func_0x80059e00(iVar1,0);
    if (iVar1 == 2) {
      _DAT_800e1134 = 0x6020000;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
      _DAT_800e10ec = _DAT_800e10ec | 0x100;
      *(undefined1 *)((int)param_1 + 0x207) = 1;
    }
    _DAT_800e1354 = param_1[0x89];
    _DAT_800e1358 = param_1[0x8a];
    DAT_800e139f = DAT_800e139f | 0x80;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *param_1 = *param_1 | 0x1000;
    _DAT_800e1130 = _DAT_800e1130 | 0x1000;
    _DAT_800e1326 = *(short *)((int)param_1 + 0x66) + 0x800;
    func_0x80052c6c(0x14,0x78,0);
  }
  else if (*(char *)((int)param_1 + 6) != '\x01') {
    return;
  }
  _DAT_800e1330 = *(undefined2 *)(param_1 + 0x80);
  _DAT_800e1334 = *(undefined2 *)(param_1 + 0x81);
  func_0x8003331c(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar1 != 0) {
    param_1[1] = 0x1030000;
    *(undefined1 *)((int)param_1 + 0x2ba) = 0x96;
    *(undefined1 *)((int)param_1 + 0x2ce) = 0x96;
    *(undefined1 *)(param_1 + 0xb6) = 0x96;
    if ((*(byte *)((int)param_1 + 0x207) & 1) != 0) {
      *(undefined1 *)((int)param_1 + 0x2ba) = 0xfa;
      *(undefined1 *)((int)param_1 + 0x2ce) = 0xfa;
    }
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    *param_1 = *param_1 & 0xffffefff;
  }
  if (*(char *)((int)param_1 + 0x1e9) == '\b') {
    local_28 = 0x76c;
    local_26 = 0x100;
    local_24 = 0;
    uVar3 = param_1[0x8d];
    func_0x80037780(0x1bb8,(int)*(short *)((int)param_1 + 0x66),uVar3 + 0xee8,&local_28);
    local_28 = 2000;
    local_26 = 0;
    func_0x80037780(0x11fa0,(int)*(short *)((int)param_1 + 0x66),uVar3 + 0xee8,&local_28);
    func_0x80052bd0(6,0);
    func_0x80052c6c(8,0xfa,3);
    func_0x80052bd0(3,0xf);
    func_0x80052bd0(2,0x14);
    func_0x80052c6c(0x46,100,0xb);
    func_0x80052bd0(3,0x19);
    func_0x80052c6c(0xd,0xfa,0x19);
    func_0x80052bd0(3,0x28);
    func_0x80052bd0(3,0x2d);
    func_0x80052bd0(3,0x32);
    func_0x80052c6c(0xd,0xfa,0x32);
    func_0x80052bd0(3,0x41);
    func_0x80052bd0(10,0x46);
    func_0x80052c6c(8,0xfa,0x46);
  }
  if (((*(byte *)((int)param_1 + 0x207) & 1) != 0) && (*(char *)((int)param_1 + 0x1e9) == '\x1e')) {
    uVar3 = param_1[0x8d];
    *(uint *)(uVar3 + 0xeb0) = *(uint *)(uVar3 + 0xeb0) | 0x80;
    *(undefined4 *)(uVar3 + 0xfe0) = 0x30;
    *(undefined4 *)(uVar3 + 0xfe4) = 0x202020;
    uVar2 = func_0x80033604();
    local_28 = (uVar2 & 0xff) * -2 + 0x86c;
    uVar2 = func_0x80033604();
    local_26 = (uVar2 & 0xff) * -2 + 0x100;
    uVar2 = func_0x80033604();
    local_24 = (uVar2 & 0xff) * -2 + 0x100;
    uVar4 = param_1[0x8d];
    uVar3 = func_0x80033604();
    func_0x80037780((uVar3 & 0xff) * 2 + 0x1fa0,(int)*(short *)((int)param_1 + 0x66),uVar4 + 0xee8,
                    &local_28);
  }
  if (8 < *(byte *)((int)param_1 + 0x1e9)) {
    uVar2 = func_0x80033604();
    local_28 = (uVar2 & 0xff) * -2 + 0x86c;
    uVar2 = func_0x80033604();
    local_26 = (uVar2 & 0xff) * -2 + 0x100;
    uVar2 = func_0x80033604();
    local_24 = (uVar2 & 0xff) * -2 + 0x100;
    uVar4 = param_1[0x8d];
    uVar3 = func_0x80033604();
    func_0x80037780((uVar3 & 0xff) * 2 + 0x830,(int)*(short *)((int)param_1 + 0x66),uVar4 + 0xee8,
                    &local_28);
    uVar2 = func_0x80033604();
    local_28 = (uVar2 & 0xff) * -2 + 0x8d0;
    uVar3 = func_0x80033604();
    func_0x80037780((uVar3 & 0xff) * 2 + 0x830 | 0x10000,(int)*(short *)((int)param_1 + 0x66),
                    uVar4 + 0xee8,&local_28);
  }
  return;
}
