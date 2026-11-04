/* FUN_8009ad3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ad3c  body 0x8009ad3c..0x8009af6f  size 564 B
 * body sha256 36f9f98f84263b74c2ac8bc3c227863de74e9904a7bd03415e12eb8c50c647f5
 * provider record sha256 3707e26f332fc23bf933fa5f142e712d5689888bf011e75ce8f753db6c181834
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009ad3c(void)

{
  FUN_80052df4();
  while ((DAT_800e10ec & 0x10000) != 0) {
    FUN_8004cd88(1);
  }
  DAT_8011a378 = 0;
  FUN_8004cd54(1,FUN_8009b250);
  FUN_8004cd88(1);
  DAT_800e1164 = *DAT_800dfb58;
  DAT_800e1158 = (int)DAT_800e1164;
  DAT_800e1166 = DAT_800dfb58[1];
  DAT_800e115c = (int)DAT_800e1166;
  DAT_800e1168 = DAT_800dfb58[2];
  DAT_800e1160 = (int)DAT_800e1168;
  DAT_800e1196 = DAT_800dfb58[3];
  DAT_800e12d2 = *(byte *)((int)DAT_800dfb58 + 0xb);
  DAT_800e138e = (ushort)DAT_800e12d2 * -0x708;
  DAT_800e12e4 = DAT_800e1164;
  DAT_800e12e6 = DAT_800e1168;
  FUN_80027148(*(undefined1 *)(DAT_800dfb58 + 5));
  DAT_800e8cae = DAT_800e8caa + (DAT_800e8ca8 + 1) * 0x100;
  DAT_800e8caa = (ushort)*(byte *)((int)DAT_800dfb58 + 9);
  if (DAT_800e8ca8 != *(byte *)(DAT_800dfb58 + 4)) {
    DAT_800e8ca8 = (ushort)*(byte *)(DAT_800dfb58 + 4);
    FUN_80064ff0();
  }
  FUN_80076a08();
  FUN_800337c4();
  FUN_800635b0();
  while ((DAT_800e10ec & 0x2000000) != 0) {
    FUN_8004cd88(1);
  }
  FUN_80083c14((int)DAT_800e8cac);
  FUN_800551e0();
  FUN_800274e4(0,0);
  FUN_80083afc(1);
  DAT_800e9183 = 1;
  FUN_8004cd88();
  if ((DAT_800e110c & 0x400000) != 0) {
    DAT_800e110c = DAT_800e110c & 0xffbfffff;
  }
  return;
}
