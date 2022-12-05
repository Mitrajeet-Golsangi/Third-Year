import React from 'react';

import {
	FaFacebookF,
	FaGithub,
	FaGoogle,
	FaInstagram,
	FaLinkedin,
	FaTwitter,
} from 'react-icons/fa';

const SocialMediaLink = ({ social }) => {
	return (
		<a
			className="btn btn-link btn-floating btn-lg text-dark m-1"
			href="#!"
			role="button"
			data-mdb-ripple-color="dark"
		>
			{social}
		</a>
	);
};

const Footer = () => {
	return (
		<footer
			className="text-center text-white"
			style={{ backgroundColor: '#f1f1f1' }}
		>
			<div className="container pt-4">
				<section className="mb-4">
					{/* ------------------------------------- Facebook ------------------------------------- */}
					<SocialMediaLink social={<FaFacebookF />} />

					{/* ------------------------------------- Twitter ------------------------------------- */}
					<SocialMediaLink social={<FaTwitter />} />

					{/* ------------------------------------- Google ------------------------------------- */}
					<SocialMediaLink social={<FaGoogle />} />

					{/* ------------------------------------- Instagram ------------------------------------- */}
					<SocialMediaLink social={<FaInstagram />} />

					{/* ------------------------------------- Linkedin ------------------------------------- */}
					<SocialMediaLink social={<FaLinkedin />} />

					{/* ------------------------------------- Github ------------------------------------- */}
					<SocialMediaLink social={<FaGithub />} />
				</section>
			</div>

			{/* ------------------------------------- Copyright ------------------------------------- */}
			<div className="text-center text-light bg-dark p-3">
				© 2022 Copyright
				<a
					className="link link-success mx-2"
					href="https://mitrajeetgolsangi.com/"
				>
					Mitrajeet Golsangi
				</a>
			</div>
			{/* ------------------------------------- Copyright ------------------------------------- */}
		</footer>
	);
};

export default Footer;
