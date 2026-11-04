/* FUN_80164b50
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80164b50  body 0x80164b50..0x80164bfb  size 172 B
 * body sha256 2b53039c9189f46533c47d155d930970b30baeb5a0c2817195faf6060f7dbeb8
 * provider record sha256 03e200ce9184f06ca3286f28ca5e5695dbd9afa32c1c739fc740361bc5ffc525
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164b50(uint *param_1,short param_2)

{
  ushort uVar1;
  
  if ((DAT_800e9012 & 8) == 0) {
    *param_1 = 0;
  }
  else {
    *param_1 = *param_1 | 0x1062;
  }
  uVar1 = func_0x80033604();
  *(ushort *)(param_1 + 10) = param_2 + (uVar1 & 0xff) * 4;
  *(undefined2 *)((int)param_1 + 0x11e) = 0;
  uVar1 = func_0x80033604();
  *(ushort *)(param_1 + 0xb) = (uVar1 & 0x7f) + 100;
  *(undefined2 *)((int)param_1 + 0x2a) = 0;
  *(undefined1 *)((int)param_1 + 0x111) = 0x14;
  *(undefined2 *)((int)param_1 + 0x2e) = 0;
  uVar1 = func_0x80033604();
  *(ushort *)(param_1 + 0xc) = (uVar1 & 0xff) << 4;
  *(undefined2 *)((int)param_1 + 0x32) = 0;
  return;
}
