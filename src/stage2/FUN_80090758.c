/* FUN_80090758
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80090758  body 0x80090758..0x80090827  size 208 B
 * body sha256 b0ebdd60e17614893ff40bd10b66a58c443410ac602ef4add40dd419dd6e86ab
 * provider record sha256 ae289958025acd48a523ef3407cb64707b3586feaafe635f93b3026bad79710e
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80090758(void)

{
  byte bVar1;
  int unaff_s0;
  undefined2 uStack00000010;
  undefined2 uStack00000014;
  
  _DAT_8013a388 = DAT_80112784;
  FUN_8006c070(0);
  bVar1 = FUN_80091738((int)DAT_800e8ca8,(int)DAT_800e8caa);
  *(byte *)(unaff_s0 + 0x1a) = bVar1;
  FUN_800479c8(DAT_800c52dc + 0x44807U & 0xfffffff8,&DAT_8012f5a0,
               *(undefined2 *)
                (&DAT_8012f8ec + (uint)*(ushort *)(&DAT_80130cba + (uint)bVar1 * 8) * 2));
  uStack00000010 = 0x1c0;
  uStack00000014 = 0x40;
  *(undefined1 *)(unaff_s0 + 2) = 1;
  *(undefined1 *)(unaff_s0 + 3) = 0;
  *(undefined2 *)(unaff_s0 + 0x58) = 0;
  *(undefined2 *)(unaff_s0 + 0x5a) = 0;
  FUN_80090e10();
  FUN_80097fd0();
  return;
}
