/* FUN_80084420
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80084420  body 0x80084420..0x800844cb  size 172 B
 * body sha256 c044cb4265cc51934f448b5b7781e00b245efc3e20e3795a2c248c444d4a21e3
 * provider record sha256 db3d373a7a5b0d90581102ec9d11c3cd28b0320d188d65448ac9396af43e8e7a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80084420(void)

{
  if (DAT_800e9183 != '\x02') {
    if ((DAT_800e10ec & 0x20000000) == 0) {
      FUN_80026910(*(undefined2 *)
                    (DAT_800e8cac * 2 +
                    *(int *)((&PTR_PTR_8011c3b0)[DAT_800e8ca8] + DAT_800e8caa * 4)));
      FUN_80026a88();
    }
    else {
      DAT_800e10ec = DAT_800e10ec & 0xdfffffff;
    }
  }
  return;
}
