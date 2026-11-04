/* FUN_80052f40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052f40  body 0x80052f40..0x80052ffb  size 188 B
 * body sha256 c0fc3481771cc77d62bfa6d8c572aa5d0a6fa7eadddf6a0e06214dc7ddc08494
 * provider record sha256 2d0c860189deaca81513a4dcac18442d30ae8dd4e3bb3ed190dcd8114db256ca
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80052f40(void)

{
  FUN_8004ce90(0);
  FUN_80027650(0);
  DAT_8010bfa8 = DAT_8010bfa8 << 1 | 1;
  do {
    if ((DAT_800e10f0 & 3) == 0) {
      FUN_800540f0();
    }
    else {
      if ((DAT_800e10f0 & 3) != 1) {
        DAT_8010bfa8 = DAT_8010bfa8 << 1;
        FUN_8004cec4(0);
        DAT_800e9182 = 2;
        FUN_8004cdd4();
        return;
      }
      FUN_8005497c();
    }
    FUN_8004cd88(1);
  } while( true );
}
