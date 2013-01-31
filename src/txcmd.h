// -*- C++ -*-
//$Id: txcmd.h,v 2.34 2012/05/11 17:06:48 grimm Exp $
// Copyright (c)  INRIA/apics (Jose' Grimm) 2008

// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  use, 
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRIA at the following URL
// "http://www.cecill.info". 
// (See the file COPYING in the main directory for details)

// This file contains some forward declarations, some typedef,
// and most of all enums of tralics.



// next three enum are BIGGG. All variables end with _cmd or _code
// in contradiction with all other enums.

// Command codes.
enum symcodes
{
  // Lets start with the catcodes
  escape_catcode= 0, open_catcode, close_catcode, dollar_catcode, alignment_catcode,
  eol_catcode, parameter_catcode,
  hat_catcode, underscore_catcode, ignored_catcode,
  space_catcode, letter_catcode, other_catcode, active_catcode,
  comment_catcode, invalid_catcode, special_catcode,
  // Now the commands
  inhibit_xml_cmd,
  endv_cmd,
  section_cmd,
  label_cmd,ref_cmd,eqref_cmd,
  par_cmd,ignorep_cmd,
  start_par_cmd,
  endcsname_cmd,
  multicolumn_cmd,
  dont_expand_cmd, 
  atdocument_cmd,
  fvset_cmd,
  biblio_cmd,
  aparaitre_cmd,
  citation_cmd,end_citation_cmd,bpers_cmd,cititem_cmd,bibitem_cmd,cite_cmd,
  cite_type_cmd, 
  bib_cmd, self_insert_cmd,thebibliography_cmd,end_thebibliography_cmd,
  footcitepre_cmd, cite_one_cmd,solvecite_cmd,vglue_cmd,xgetfontsize_cmd,
  numberwithin_cmd,ifdefinable_cmd,dblarg_cmd,
  // math_cmd, math1_cmd,
  titlepage_cmd,color_cmd,
  backslash_cmd,hline_cmd,skip_cmd,hfill_cmd,vfill_cmd,sub_cmd,
  oldfont_cmd,argfont_cmd,noargfont_cmd, fontsize_cmd,ltfont_cmd,
  item_cmd, pers_cmd,doc_class_cmd,package_cmd, if_package_loaded_cmd,
  if_package_later_cmd,if_package_with_cmd, provides_package_cmd,
  pass_options_cmd, declare_options_cmd, options_not_used_cmd,
  process_options_cmd,execute_options_cmd, load_with_options_cmd,
  needs_format_cmd, at_end_of_class_cmd,inputclass_cmd,
  subfigure_cmd, float_cmd,pop_stack_cmd,
  box_cmd,  math_comp_cmd, big_cmd,
  style_cmd,limits_cmd,nonumber_cmd, nonscript_cmd,
  eqno_cmd, tag_cmd,linebreak_cmd,
  fancy_cmd, xfancy_cmd, xthepage_cmd, url_cmd,hanl_cmd, addatt_cmd,
  over_cmd,popmodule_cmd,pushmodule_cmd,
  begingroup_cmd, startprojet_cmd,declaretopics_cmd,footnote_cmd,caption_cmd,
  ra_startdoc_cmd,fnhack_cmd,interpret_rc_cmd,
  centering_cmd,fbox_cmd,save_box_cmd,
  hspace_cmd,includegraphics_cmd,unimp_font_cmd,
  error_cmd,glo_cmd,xmllatex_cmd,specimp_cmd,unimp_cmd,cr_cmd,
  scan_glue_cmd,kern_cmd,
  make_box_cmd,
  char_num_cmd,
  cst1_cmd, cst2_cmd, 
  cst_cmd, ignoreA_cmd,
  ding_cmd,grabenv_cmd,
  selectfont_cmd, usefont_cmd,isin_cmd,
  nobreakspace_cmd,
  file_cmd,specmath_cmd,
  xmlelt_cmd,newcolumntype_cmd,
  arg_font_cmd,rule_cmd,reevaluate_cmd,
  soul_cmd, trees_cmd,matter_cmd, index_cmd, gloss_cmd,
  only_preamble_cmd,toc_cmd,
  listfiles_cmd, typein_cmd,cons_cmd,ipa_cmd, nomath_cmd,
  // start ENV
  first_env_cmd,
  document_cmd,keywords_cmd,center_cmd,figure_cmd,table_cmd,
  glossaire_cmd,itemize_cmd,enumerate_cmd,description_cmd, list_cmd, 
  usecounter_cmd,
  ignore_env_cmd, ignore_content_cmd,raw_env_cmd,
  math_env_cmd,RAsection_env_cmd,
  tabular_env_cmd,verbatim_env_cmd,
  minipage_cmd,
  picture_env_cmd,
  xmlelement_env_cmd,  filecontents_env_cmd,
  last_env_cmd,
  end_document_cmd,end_keywords_cmd,end_center_cmd,end_figure_cmd,end_table_cmd,
  end_glossaire_cmd,end_itemize_cmd,end_enumerate_cmd,end_description_cmd,
  end_list_cmd,
  end_ignore_env_cmd, end_ignore_content_cmd,end_raw_env_cmd,
  end_math_env_cmd,end_RAsection_env_cmd,
  end_tabular_env_cmd,end_verbatim_env_cmd,
  end_minipage_cmd, end_picture_env_cmd,end_xmlelement_env_cmd,
  end_filecontents_env_cmd,
  // end ENV
  invalid_cmd,
  begin_cmd, end_cmd, // is this OK ?????
  mathordb_cmd, // bold math ord
  mathord_cmd,mathbin_cmd,mathrel_cmd,mathinner_cmd,mathbetween_cmd,
  mathopen_cmd,mathclose_cmd,mathop_cmd,mathopn_cmd,
  mathspace_cmd,mathfont_cmd,
  math_font_cmd,
  math_list_cmd, math_xml_cmd, // these are not real command codes...
  left_cmd,right_cmd,
  special_math_cmd, line_cmd,
  leave_v_mode_cmd,
  epsfbox_cmd, put_cmd,bezier_cmd, dashline_cmd,curves_cmd,
  thickness_cmd, bibliographystyle_cmd,insertbibliohere_cmd,
  footcitesep_cmd,expandtwoargs_cmd,removeelement_cmd,
  // These are mode independent
  first_mode_independent,
  case_shift_cmd,etex_cmd, xkeyval_cmd,makelabel_cmd,
  ignore_cmd, relax_cmd,nolinebreak_cmd,ignore_one_argument_cmd,
  ignore_two_argument_cmd, defineverbatimenv_cmd,saveverb_cmd,
  makeatletter_cmd,makeatother_cmd, add_to_macro_cmd,
  numberedverbatim_cmd,unnumberedverbatim_cmd,
  after_assignment_cmd,un_box_cmd,extension_cmd,setlanguage_cmd,
  xray_cmd,move_cmd,leader_ship_cmd,tracingall_cmd,newif_cmd,
  newcount_cmd,newboolean_cmd,
  setboolean_cmd,for_cmd,kvo_family_cmd,
  ifthenelse_cmd, whiledo_cmd,shortverb_cmd,  newcounter_cmd,aftergroup_cmd,
  ifstar_cmd,ifnextchar_cmd,typeout_cmd,  calc_cmd, 
  fp_cmd, fpif_cmd, fpi_cmd, // commands from the fp package,
  verb_cmd,thm_aux_cmd,start_thm_cmd,
  setmode_cmd,testopt_cmd,
  sp_deflist_cmd, selective_sanitize_cmd, latex_error_cmd,
  change_element_name_cmd,check_date_cmd,formatdate_cmd,

  // From now on these are ok for \the
  min_internal,   
  char_given_cmd,math_given_cmd,last_item_cmd,
  // Commands from here may be prefixed with \global
  max_non_prefixed_command,
  toks_register_cmd,
  assign_toks_cmd,
  assign_int_cmd,
  assign_dimen_cmd,
  assign_glue_cmd,
  assign_mu_glue_cmd,
  assign_font_dimen_cmd,
  assign_font_int_cmd,
  assign_enc_char_cmd,
  set_aux_cmd,
  set_prev_graf_cmd,
  set_page_dimen_cmd,
  set_page_int_cmd,
  set_box_dimen_cmd,
  set_shape_cmd,
  def_code_cmd,
  def_family_cmd,
  set_font_cmd,
  def_font_cmd,
  register_cmd,
  set_mathprop_cmd,
  set_mathchar_cmd,

  max_internal,
  advance_cmd, multiply_cmd, divide_cmd, prefix_cmd, let_cmd,
  shorthand_def_cmd,read_to_cs_cmd,def_cmd,set_box_cmd,
  set_interaction_cmd,
  max_command, // After this, command is expanded
  undef_cmd, // not a valid cmd
  xspace_cmd,ensuremath_cmd,multispan_cmd, zapspace_cmd,stripprefix_cmd,
  latex_ctr_cmd, hexnumber_cmd,
  first_of_one_cmd,
  first_of_two_cmd,afterfi_cmd,afterelsefi_cmd,
  ifempty_cmd, ifundefined_cmd,get_config_cmd,
  the_cmd,strippt_cmd,convert_cmd,
  obracket_cmd,oparen_cmd,csname_cmd,
  expandafter_cmd,noexpand_cmd,
  scanupdown_cmd,sideset_cmd,
  specchar_cmd, car_cmd,
  split_cmd,gobble_cmd,refstepcounter_cmd,
  month_day_cmd,mathversion_cmd,
  a_cmd,accent_cmd, while_cmd, iwhile_cmd,loop_cmd,
  counter_cmd,setlength_cmd,useverb_cmd,random_cmd,
  input_cmd,if_test_cmd,fi_or_else_cmd,top_bot_mark_cmd,
  // keep these 8 in order at the end
  user_cmd,userl_cmd,usero_cmd,userlo_cmd,
  userp_cmd,userlp_cmd,userop_cmd,userlop_cmd,
};

// Subtypes associated to a type. A given integer has more than one meaning.
enum subtypes {
  // pointers into eqtb_int_table
  cat_code_offset = 0,
  math_code_offset = cat_code_offset+nb_characters,
  lc_code_offset = math_code_offset+nb_characters,
  uc_code_offset = lc_code_offset+nb_characters,
  sf_code_offset = uc_code_offset+nb_characters,
  del_code_offset = sf_code_offset+nb_characters,
  count_reg_offset = del_code_offset+nb_characters,
  mu_reg_offset = count_reg_offset+nb_registers,
  other_int_offset = mu_reg_offset+nb_registers,
  // some integer parameters
  pretolerance_code=other_int_offset, tolerance_code,linepenalty_code,
  hyphenpenalty_code,exhyphenpenalty_code,clubpenalty_code,widowpenalty_code,
  displaywidowpenalty_code,brokenpenalty_code,binoppenalty_code,
  relpenalty_code,predisplaypenalty_code,postdisplaypenalty_code,
  interlinepenalty_code,doublehyphendemerits_code,finalhyphendemerits_code,
  adjdemerits_code,mag_code,delimiterfactor_code,looseness_code,
  time_code,day_code,month_code,year_code,showboxbreadth_code,
  showboxdepth_code,hbadness_code,vbadness_code, pausing_code,
  tracingonline_code,tracingmacros_code,tracingstats_code, 
  tracingparagraphs_code, tracingpages_code, tracingoutput_code,
  tracinglostchars_code, tracingcommands_code, tracingrestores_code,
  tracingassigns_code, tracinggroups_code,tracingifs_code, tracingmath_code,
  tracingscantokens_code,tracingnesting_code, TeXXetstate_code,
  uchyph_code, outputpenalty_code, maxdeadcycles_code, hangafter_code,
  floatingpenalty_code,globaldefs_code, fam_code, escapechar_code,
  defaulthyphenchar_code, defaultskewchar_code, endlinechar_code,
  newlinechar_code, language_code, lefthyphenmin_code, righthyphenmin_code,
  holdinginserts_code, errorcontextlines_code,incentering_code,fpseed_code,
  list_depth_code, list_ctr_code,
  nomath_code, notrivialmath_code, cur_font_loc,
  predisplaydirection_code, lastlinefit_code,savingdiscards_code,
  savinghyphcodes_code,
  atmathversion_code,mathprop_ctr_code,use_subfigure_code,
  textfont_code,scriptfont_code=textfont_code+16,
  scriptscriptfont_code=scriptfont_code+16,
  math_font_pos=scriptscriptfont_code+16,
  integer_table_size,
  // some dimen parameters 
  dimen_reg_offset=0, 
  parindent_code=dimen_reg_offset+nb_registers,mathsurround_code,
  lineskiplimit_code,
  hsize_code,vsize_code,maxdepth_code,splitmaxdepth_code,boxmaxdepth_code,
  hfuzz_code,vfuzz_code,delimitershortfall_code,nulldelimiterspace_code,
  scriptspace_code,predisplaysize_code,displaywidth_code,displayindent_code,
  overfullrule_code,hangindent_code,hoffset_code,voffset_code,
  emergencystretch_code, unitlength_code,textheight_code,textwidth_code,
  linewidth_code,columnwidth_code,
  // some mu glue
  dimension_table_size,


  // pointers into toks_registers
  output_code=nb_registers,everypar_code,everymath_code,everydisplay_code,
  everyhbox_code, everyvbox_code,everyjob_code,everycr_code,errhelp_code,
  theorem_style_code, theorem_bodyfont_code,theorem_headerfont_code,
  thm_unused_code,everyxbox_code,everyeof_code,everybibitem_code,
  toks_register_size,

  // pointers into glue_table
  lineskip_code = nb_registers,baselineskip_code,parskip_code,
  abovedisplayskip_code,
  belowdisplayskip_code,abovedisplayshortskip_code,belowdisplayshortskip_code,
  leftskip_code,rightskip_code,topskip_code,splittopskip_code,
  tabskip_code,spaceskip_code,xspaceskip_code,parfillskip_code,
  calcAskip_code, calcBskip_code, 
  thinmuskip_code,medmuskip_code,thickmuskip_code,muskip_reg_offset,
  glue_table_size=thickmuskip_code+nb_registers,

  noexpand_code=0,
  chartoobig,
  relax_code = nb_characters,
  //  for section_cmd,
  part_code=0, chapter_code, section_code,subsection_code,
  subsubsection_code,paragraph_code,subparagraph_code, endsec_code, 
  toplevel_sec_code,
  // for cite_cmd
  cite_code=0,footcite_code,nocite_code,refercite_code,yearcite_code,
  natcite_code,  natcite_e_code,
  // for skip_cmd
  smallskip_code=0, medskip_code, bigskip_code,
  // for hfill vfill
  hfil_code=1,hfill_code,hfilneg_code, hss_code,
  vfil_code=1,vfill_code,vfilneg_code,vss_code,
  // for fonts
  rm_family_code=0, sf_family_code, tt_family_code,
  md_series_code,bf_series_code,up_shape_code,it_shape_code,
  sl_shape_code, sc_shape_code,em_code,normalfont_code,
  // for fontsize_cmd, dont change the order
  generic_size_code=0,Tiny_code=1,tiny_code,scriptsize_code,footnotesize_code,
  small_code,
  normalsize_code,large_code,Large_code,LARGE_code,huge_code,Huge_code,
  // fort box_cmd
  // for soul
  soul_sup_code =0, soul_sub_code,soul_oldstyle_code,
  soul_caps_code, soul_hl_code, soul_so_code, soul_st_code,  soul_ul_code,
  mbox_code=0,text_code,makebox_code,
  // for math_comp
  ord_noad=0, op_noad, bin_noad,rel_noad,open_noad,close_noad,
  punct_noad,inner_noad,under_noad,over_noad,between_noad,
  // for big_cmd
  big_code=0,Big_code,bigg_code,Bigg_code,
  bigl_code,Bigl_code,biggl_code,Biggl_code,
  bigr_code,Bigr_code,biggr_code,Biggr_code,
  bigm_code,Bigm_code,biggm_code,Biggm_code,
  // for style_cmd
  displaystyle_code =0,textstyle_code,scriptstyle_code,scriptscriptstyle_code,
  // for over_cmd
  above_code =0,over_code,atop_code,abovewithdelims_code,overwithdelims_code,
  atopwithdelims_code,
  // for centering_code
  center_code=1, quote_code, quotation_code,flushleft_code, flushright_code,
  verse_code,
  // for fbox_cmd
  fbox_code= 0,framebox_code,rotatebox_code,scalebox_code, dashbox_code,
  raisebox_code,
  // for cr
  cr_code=0,crcr_code,crwithargs_code,mycr_code,
  // for eqno
  eqno_code =0 ,leqno_code,
  hrule_code=0,  vrule_code, rule_code,
  // for unimp
  accent_code =0,delimiter_code,halign_code,
  ignorespaces_code,insert_code,mark_code,marks_code,mathaccent_code,
  mathchar_code,noalign_code,noboundary_code,nonscript_code,
  omit_code,penalty_code,radical_code,vadjust_code,valign_code,vcenter_code,
  span_code,dump_code,
  message_code,errmessage_code,
  atatend_code, widthof_code,heightof_code,depthof_code,discretionary_code,
  textquotestraightbase_code,textquotestraightdblbase_code,
  textlbrackdbl_code,textrbrackdbl_code,
  textcompwordkmark_code,texttildelow_code, textcentoldstyle_code,
  textdollaroldstyle_code,textcopyleft_code,textzerooldstyle_code, 
  textoneoldstyle_code,  texttwooldstyle_code,textthreeoldstyle_code,
  textfouroldstyle_code, textfiveoldstyle_code,  textsixoldstyle_code,
  textsevenoldstyle_code,texteightoldstyle_code,textnineoldstyle_code,
  textcapitalcompwordmark_code,textguarani_code,textinterrobangdown_code,
  textdiscount_code,textascendercompwordmark_code,textdblhyphen_code,
  textleaf_code, textdied_code,textdivorced_code,textborn_code, 
  textmarried_code, textblank_code, allowbreak_code,
  abort_code,sleep_code, prompt_code,
  // for unimp_font
  DeclareTextCommandDefault_code=0,ProvideTextCommand_code,
  ProvideTextCommandDefault_code, TextSymbolUnavailable_code,
  DeclareTextCommand_code, DeclareTextSymbolDefault_code, UseTextSymbol_code,
  UndeclareTextCommand_code, DeclareFontEncodingDefaults_code, 
  DeclareSizeFunction_code, DeclareTextAccent_code, UseTextAccent_code,
  DeclareTextSymbol_code, DeclareFontFamily_code, DeclareFontEncoding_code,
  DeclareTextCompositeCommand_code, DeclareTextComposite_code,
  DeclareFontSubstitution_code, DeclarePreloadSizes_code,
  DeclareMathSizes_code, DeclareErrorFont_code,
  DeclareFontShape_code,DeclareFixedFont_code,DeclareMathVersion_code,
  DeclareSymbolFont_code,  SetSymbolFont_code,   DeclareMathAlphabet_code,
  SetMathAlphabet_code,  DeclareMathAccent_code,  DeclareMathSymbol_code,
  DeclareMathDelimiter_code, DeclareMathRadical_code, 
  DeclareSymbolFontAlphabet_code, DeclareTextFontCommand_code,
  DeclareOldFontCommand_code,setfontsize_code, setsize_code,
  // for index
  index_code=0,glossary_code,printindex_code,printglossary_code,
  makeindex_code,makeglossary_code,newindex_code,
  // for scan_glue 
  hskip_code=1, vskip_code,mskip_code,
  // for make_box
  box_code=0,copy_code, lastbox_code,vsplit_code,vtop_code,vbox_code,
  hbox_code, xbox_code, parbox_code, marginpar_code,usebox_code,
  //  for color
  definecolor_code=0, color_code, normalcolor_code,pagecolor_code,
  colorbox_code, fcolorbox_code,
  // for loops 
  xkv_for_n_code=0,xkv_for_en_code, for_code,tfor_code,forloop_code,
  iforloop_code,tforloop_code, breaktfor_code,xkv_breaktfor_code, 
  xkv_for_i_code,xkv_for_o_code, xkv_for_eo_code,
  // for cst_cmd and cst1_cmd
  // iso-8859-1 codes in order starting with A0
  nobreakspace_code=160,
  ss_code,i_code,napos_code,
  // other
  dots_code,ldots_code,quad_code,qquad_code,space_code,
  dollar_code, percent_code, amp_code, exclam_code, comma_code, lbrace_chr, 
  rbrace_chr, j_code,underscore_code,sharp_code,
  textasciicircum_code,
  dash_code, numero_code,Numero_code,ier_code,
  iere_code,iers_code,ieres_code,ieme_code,iemes_code, 
  textvisiblespace_code,textnospace_code,LaTeX_code,
  TeX_code,slash_code,  textbackslash_code,null_code, 
  SS_code,ouml_code,
  msharp_code, natural_code,flat_code,
  textasciigrave_code,textasciiacutex_code,
  textbullet_code,
  Hcaron_code,hcaron_code, tdagger_code, tddagger_code,nbsp_code,
  guillemet_fg_code,  guillemet_og_code, emdash_code,endash_code,
  last_entity_code,
  // lower case is always one more than upper 
  Udiamacro_cc=0,udiamacro_cc,Udiaacute_cc, udiaacute_cc,
  Udiacaron_cc,udiacaron_cc, Udiagrave_cc,udiagrave_cc, 
  Adiamacro_cc,adiamacro_cc,Adotmacro_cc, adotmacro_cc,
  Oogonmacron_cc,oogonmacron_cc, Odiamacro_cc,odiamacro_cc,
  Otilmacro_cc,otilmacro_cc,
  Odotmacro_cc,odotmacro_cc,Ccedilacute_cc,ccedilacute_cc,
  Ebaracute_cc,ebaracute_cc,Itremaacute_cc, itremaacute_cc,
  Otildeaigu_cc, otildeaigu_cc,  Obaraigu_cc, obaraigu_cc,
  Sdotacute_cc,sdotacute_cc,Utildeacute_cc,utildeacute_cc,
  Aciracute_cc,  aciracute_cc, Eciracute_cc,eciracute_cc,
  Acirtilde_cc,acirtilde_cc,Ebargrave_cc,ebargrave_cc,
  Acirgrave_cc, acirgrave_cc,Acirtilde,acirtilde,
  Ecedrond_cc, ecedrond_cc,Ldotbar_cc, ldotbar_cc,Rdotbar_cc, rdotbar_cc,
  Otildedp_cc,otildedp_cc,Obargrave_cc,obargrave_cc,
  Sdotcaron_cc,sdotcaron_cc,Sdotdot_cc, sdotdot_cc,Acirdot_cc,acirdot_cc,
  Abreveacute_cc, abreveacute_cc,Abrevegrave_cc,abrevegrave_cc,
  Abrevexx_cc, abrevexx_cc,Abrevetilde_cc,abrevetilde_cc,
  Abrevedot_cc,abrevedot_cc,  Ecirgrave_cc,  ecirgrave_cc, 
  Ecirxx_cc, ecirxx_cc, Ecirtilde_cc, ecirtilde_cc, 
  Ecirdot_cc,ecirdot_cc,Acirxx_cc,acirxx_cc, 
  Ocirgrave_cc,   ocirgrave_cc,  Ociracute_cc,ociracute_cc,
  Ocirxx_cc, ocirxx_cc, Ocirtilde_cc,ocirtilde_cc,
  Ocirdot_cc,ocirdot_cc,  Oacuteyy_cc,  oacuteyy_cc,
  Ograveyy_cc,ograveyy_cc,Oxxyy_cc,oxxyy_cc,
  Otildeyy_cc,otildeyy_cc,Odotyy_cc,odotyy_cc,
  Uacuteyy_cc,  uacuteyy_cc, Ugraveyy_cc,ugraveyy_cc,
  Uxxyy_cc,uxxyy_cc,Utildeyy_cc,utildeyy_cc, Udotyy_cc,udotyy_cc,
  unused_accent_even_cc,  unused_accent_odd_cc,
  en_dash_coce, em_dash_code,
  special_table_length,
  // for file_cmd
  input_code=0,endinput_code,inputifexists_code,ifexists_code,openin_code,
  closein_code, include_code,end_all_input_code,Input_code,scantokens_code,
  // for participant
  participant_code =0, participante_code, participantes_code,participants_code,
  // ignore_env
  body_code=0, abstract_code,latexonly_code,xmlonly_code,subequations_code,
  // ignore_content
  htmlonly_code=0,rawhtml_code,LaTeXonly_code,comment_code,
  // parshape and others
  parshape_code=0, interlinepenalties_code, clubpenalties_code,
  widowpenalties_code, displaywidowpenalties_code,
  // for put_cmd
  put_code=0, line_code, vector_code,oval_code,multiput_code,scaleput_code,
  frame_code,
  arc_code = 0, bigcircle_code,closecurve_code, curve_code,tagcurve_code,
  dashline_code=0,drawline_code,dottedline_code,circle_code,
  // math_env
  eqnarray_code=0, eqnarray_star_code, 
  align_code, align_star_code, 
  equation_code,equation_star_code,
  multline_code,  multline_star_code, gather_code,  gather_star_code,
  aligned_code, split_code,math_code,displaymath_code,Beqnarray_code, 
  Beqnarray_star_code,
  // for line_cmd
  leftline_code=0, rightline_code, centerline_code, llap_code, rlap_code,
  // for last_item
  lastpenalty_code = it_int,
  lastkern_code = it_dimen, 
  lastskip_code=it_glue,
  inputlineno_code,badness_code,  xmlcurrentid_code,xmllastid_code,
  currentgrouplevel_code,currentgrouptype_code,currentiflevel_code,
  currentiftype_code,currentifbranch_code,etexversion_code, 
  fontcharwd_code, fontcharht_code, fontchardp_code, fontcharic_code,
  parshapelength_code, parshapeindent_code, parshapedimen_code,
  lastnodetype_code,numexpr_code,dimexpr_code,glueexpr_code,muexpr_code,
  gluestretchorder_code,  glueshrinkorder_code,  gluestretch_code,  
  glueshrink_code,mutoglue_code,gluetomu_code,xgetfontsize_code,
  // fi_or_else
  if_code=1,fi_code,else_code,or_code,
  //if_test_cmd; do not change the order of these
  if_char_code=0, if_cat_code, if_int_code, if_dim_code,
  if_odd_code, if_vmode_code, if_hmode_code, if_mmode_code,
  if_inner_code, if_void_code,if_hbox_code, if_vbox_code,
  ifx_code, if_eof_code, if_true_code,if_false_code, if_case_code,
  if_defined_code, if_csname_code, if_fontchar_code,
  if_leapyear_code,
  unless_code=32, // defined by etex
  // for newcount_cmd
  newtoks_code=0,newcount_code,newbox_code,newdimen_code,newlength_code, 
  newmuskip_code, newread_code,newwrite_code,newlanguage_code,
  // for def_cmd
  xdef_code=0,def_code,gdef_code,edef_code,let_code,
  newcommand_code,newthm_code,newenv_code,renewenv_code,renew_code, 
  provide_code,declare_math_operator_code,checkcommand_code,
  futurelet_code,
  // add_att 
  addatt_to_cur_code=0, addatt_to_last_code, addatt_to_doc_code,addatt_to_code,
  addatt_to_index_code,
  // ignore cmd
  htmlimage_code = 0,immediate_code,
  unpenalty_code,unkern_code,unskip_code,atsign_code,italiccorr_code,
  protect_code,sloppy_code, fussy_code, subitem_code, clearpage_code, 
  cleardoublepage_code, break_code, nobreak_code, newpage_code,
  samepage_code,
  fillbreak_code, goodbreak_code, eject_code, smallbreak_code, 
  medbreak_code,bigbreak_code,addnl_code,
  nointerlineskip_code, offinterlineskip_code,frenchspacing_code,
  nonfrenchspacing_code, showoverfull_code, loggingoutput_code, nofiles_code,
  showoutput_code,hrulefill_code,dotfill_code,
  pagediscards_code,splitdiscards_code,
  endL_code, endR_code, beginL_code,beginR_code,
  raggedbottom_code, flushbottom_code,  onecolumn_code, twocolumn_code,
  normalmarginpar_code,reversemarginpar_code,normalbaselines_code,
  removelastskip_code,
  // ignore_one_arg_cmd
  RAlabel_code=2, hyphenation_code,
  patterns_code,special_code,includeonly_code,fontencoding_code, 
  fontfamily_code, fontseries_code, fontshape_code,showhyphens_code,
  //ignore_two_argument_cmd
  HTMLset_code=1, fontsize_code,
  // linebreak_cmd
  pagebreak_code, nopagebreak_code, linebreak_code, nolinebreak_code,
  // fancy_cmd
  fancy_lhead_code, fancy_chead_code,fancy_rhead_code,
  fancy_lfoot_code, fancy_cfoot_code,fancy_rfoot_code,
  fancy_head_code, fancy_foot_code,fancy_hf_code,
  // extension_cmd
  openout_code=1,write_code,closeout_code,
  // xray_cmd
  show_code=0,showbox_code,showthe_code,showlists_code, showgroups_code,
  showtokens_code, showifs_code,
  unexpanded_code,detokenize_code,// awful hack, because  \showthe calls \the
  // shorthand_def_cmd
  char_def_code=0,  math_char_def_code, count_def_code,
  dimen_def_code, skip_def_code, mu_skip_def_code, toks_def_code,
  // top_bot_mark_cmd
  topmark_code=0,firstmark_code,botmark_code,splitfirstmark_code,
  splitbotmark_code,topmarks_code,firstmarks_code,botmarks_code,
  splitfirstmarks_code, splitbotmarks_code,
  // leader_ship_cmd
  shipout_code=1,leaders_code,cleaders_code,xleaders_code,
  //un_box_cmd
  unhbox_code=0,unhcopy_code,unvbox_code,unvcopy_code,
  // convert_cmd
  number_code=1,romannumeral_code,string_code,meaning_code,fontname_code,
  jobname_code,tralicsversion_code,etexrevision_code,rayear_code,
  Romannumeral_code,at_arabic_code,sanitize_code,twodigits_code,
  ra_jobname_code,attributeval_code,
  // the
  the_code = 0,  
  // latex_ctr_cmd
  arabic_code=0,roman_code,Roman_code,alph_code,Alph_code,fnsymbol_code,
  at_number_code,
  at_alph_code,at_Alph_code,at_fnsymbol_code,
  calcaux_code,
  // set_interaction_cmd
  batchmode_code=0,nonstopmode_code,scrollmode_code,errorstopmode_code,
  // mathfont_cmd
  math_f_normal=0, math_f_upright,math_f_bold,math_f_italic, math_f_bold_italic,
  math_f_script,math_f_bold_script,math_f_fraktur, math_f_doublestruck,
  math_f_bold_fraktur, math_f_sansserif,math_f_bold_sansserif,
  math_f_sansserif_italic,math_f_sansserif_bold_italic,math_f_monospace,
  // arg_font_cmd
  lsc_code=0,fsc_code,
  // mathfont_cmd
  mathtt_code=0,mathcal_code,mathbf_code,mathrm_code,mathit_code,mathbb_code,
  mathsf_code,mathnormal_code,cal_code,mathfrak_code,
  // counter_cmds
  stepcounter_code=0,addtocounter_code,setcounter_code,value_code,
  killcounter_code,addtoreset_code,
  // prefix_cmd
  global_code=8,long_code=1,outer_code=2, protected_code=4,
  // set_page_dimen_cmd
  pagegoal_code=0,pagetotal_code,pagestretch_code,
  pagefilstretch_code, pagefillstretch_code, pagefilllstretch_code,
  pageshrink_code, pagedepth_code,
  // set_page_int_cmd
  deadcycles_code=0, insertpenalties_code,interactionmode_code,
  // set_box_dimen_cmd
  wd_code=0,ht_code,dp_code,
  // move_cmd
  moveleft_code=0,moveright_code,raise_code, lower_code,
  // math commands (with arguments) and math accent codes
  mathchoice_code=0,stackrel_code,underset_code,
  overset_code,frac_code,dfrac_code,tfrac_code,cfrac_code,genfrac_code,
  binom_code,tbinom_code,dbinom_code,
  root_code,mathbox_code,cell_attribute_code,row_attribute_code,
  formula_attribute_code,thismath_attribute_code, table_attribute_code,
  math_attribute_code,   accentset_code, underaccent_code,
  multicolumn_code,last_marg_code = multicolumn_code, // following take 1 arg
  mathmi_code, mathmn_code, mathmo_code, 
  mathci_code, mathcn_code, mathcsymbol_code, mathnothing_code,
  multiscripts_code,
  sqrt_code,operatorname_code,operatornamestar_code,boxed_code,
  overline_code,underline_code,overbrace_code, underbrace_code,undertilde_code,
  phantom_code,vphantom_code,hphantom_code,smash_code,atsmash_code,
  // now comes accent commands
  acute_code,first_maccent_code=acute_code,
  grave_code,  ddot_code,   tilde_code,   widetilde_code,   bar_code,
  breve_code,   check_code,   hat_code,   widehat_code,  vec_code,
  ddddot_code, dddot_code, mathring_code, 
  overrightarrow_code,  overleftarrow_code,  overleftrightarrow_code,dot_code,
  xleftarrow_code,xrightarrow_code,
  underrightarrow_code, first_under_accent_code=underrightarrow_code,  
  underleftrightarrow_code,
  underleftarrow_code, last_maccent_code=underleftarrow_code,
  qopname_code,last_math_code, math_marker_code=last_math_code+1000, 
  //thickness
  thicklines_code=0,thinlines_code,linethickness_code,
  // for trees
  node_code=0, nodepoint_code, nodeconnect_code, anodeconnect_code,
  nodecurve_code, anodecurve_code, nodebox_code, nodeoval_code,
  nodetriangle_code,nodecircle_code, barnodeconnect_code, 
  abarnodeconnect_code, 
  mainmatter_code =0, frontmatter_code, backmatter_code,
  // month day names
  md_frenchm_code=0,  md_frenchd_code,  md_englishm_code,  md_englishd_code,
  md_germanm_code,  md_germand_code,  md_spanishm_code,  md_spanishd_code,
  // hacks
  zero_code = 0,one_code, two_code,three_code,
  fp_ident_code =0, fp_print_code, fp_set_code, fp_add_code, fp_sub_code, 
  fp_div_code, fp_mul_code, fp_abs_code, fp_neg_code, fp_iflt_code, 
  fp_ifeq_code,  fp_ifgt_code, fp_ifneg_code, fp_ifpos_code, fp_ifzero_code, 
  fp_ifint_code,fp_min_code, fp_max_code,fp_sgn_code, 
  fp_seed_code,fp_random_code,fp_round_code,fp_trunc_code,fp_clip_code,
  fp_eval_code, fp_upn_code,fp_e_code,fp_exp_code,fp_ln_code,fp_pow_code,
  fp_root_code, fp_sin_code, fp_cos_code, fp_sincos_code,
  fp_tan_code,fp_cot_code,fp_tancot_code, fp_arcsin_code, fp_arccos_code, 
  fp_arcsincos_code, fp_arctan_code,fp_arccot_code,fp_arctancot_code,
  fp_lsolve_code,fp_qsolve_code,fp_csolve_code,fp_qqsolve_code,fp_pascal_code,
  fp_last_code,
  boot_keyval_code=0,definekey_code,xdefinekey_code, define_cmdkey_code,
  define_cmdkeys_code, define_choicekey_code, define_cc_code,
  define_boolkey_code,define_boolkeys_code,key_ifundefined_code,
  disable_keys_code, 
  save_keys_code, delsave_keys_code, unsave_keys_code, preset_keys_code,
  delpreset_keys_code,  unpreset_keys_code,
  gsave_keys_code, gdelsave_keys_code, gunsave_keys_code, gpreset_keys_code,
  gdelpreset_keys_code,  gunpreset_keys_code, setrmkeys_code,setkeys_code,
  declare_optionsX_code, execute_optionsX_code, process_optionsX_code,
  classerror_code=0, classwarning_code, classwarningnoline_code, 
  classinfo_code, packageerror_code, packagewarning_code,
  packagewarningnoline_code, packageinfo_code, genericerror_code,
  genericinfo_code, genericwarning_code, messagebreak_code,
  latexerror_code,latexwarning_code, latexwarningnoline_code, latexinfo_code,
  latexinfonoline_code,
  kvo_fam_set_code=0,kvo_fam_get_code, kvo_pre_set_code, kvo_pre_get_code,
  kvo_bool_opt_code,kvo_comp_opt_code,kvo_boolkey_code,kvo_string_opt_code,
  kvo_void_opt_code,kvo_voidkey_code,kvo_disable_code,kvo_decdef_code,
  kvo_process_code,
  // letters 
  letter_ucode = 'u',letter_vcode = 'v',letter_ticode = '~'
};

