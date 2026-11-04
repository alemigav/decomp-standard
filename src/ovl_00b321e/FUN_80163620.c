/* FUN_80163620
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163620  body 0x80163620..0x801637bf  size 416 B
 * body sha256 ee82a05cac89120465ef66478c9438d4f2212af1febfa2ff6f9d65d9db3ca89d
 * provider record sha256 f8c77f559a57875b504a9af035b591448a5de50a45c5b545c9d4ed6a9026a2f6
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163620(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  uint uVar2;
  undefined1 uVar3;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 0x78) = 0xffba;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x7d) = *(undefined2 *)((int)param_1 + 0x66);
    uVar2 = func_0x80033604();
    uVar3 = 0xc0;
    if ((uVar2 & 1) != 0) {
      uVar3 = 0x40;
    }
    *(undefined1 *)((int)param_1 + 0x206) = uVar3;
    param_1[0x7a] = 0x4000f00;
  }
  if (*(short *)(param_1 + 0x1a) < 0) {
    *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + 0x80;
  }
  else {
    *(undefined2 *)(param_1 + 0x1a) = 0;
    *(undefined1 *)((int)param_1 + 0x2c5) = 0;
  }
  *(short *)((int)param_1 + 0x66) =
       *(short *)((int)param_1 + 0x66) + (short)*(char *)((int)param_1 + 0x206);
  if (*(short *)((int)param_1 + 0x1e2) < 500) {
    *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 10;
  }
  uVar1 = *(undefined2 *)(param_1 + 0x1a);
  *(undefined2 *)(param_1 + 0x1a) = 0;
  func_0x80032bd8(param_1,(int)*(short *)(param_1 + 0x7d) - (int)*(short *)((int)param_1 + 0x66),0);
  *(undefined2 *)(param_1 + 0x1a) = uVar1;
  if ((int)*(short *)((int)param_1 + 0x25e) <= (int)(param_1[0xb] + 0x30f)) {
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e) - 0x30f;
    *(undefined1 *)(param_1 + 0xaf) = 0;
    func_0x80077d18(7,param_1);
    if (-1 < *(short *)(param_1 + 0x1a)) {
      if (*(char *)(param_1 + 1) == '\x01') {
        *(undefined1 *)((int)param_1 + 5) = 0;
        *(undefined2 *)((int)param_1 + 6) = 0;
      }
      else {
        *(undefined2 *)((int)param_1 + 6) = 0x200;
      }
      *param_1 = *param_1 & 0xfffffffb;
      FUN_801665a0(param_1,0);
      *(undefined1 *)(param_1 + 0xb1) = 0;
      *(undefined1 *)((int)param_1 + 0x2c3) = 0;
      param_1[0x7a] = 0xf00;
      param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    }
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80033648(param_1);
  return;
}
